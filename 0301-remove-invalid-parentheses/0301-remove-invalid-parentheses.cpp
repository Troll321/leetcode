#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN2 = 30;
vector<string> um[MAXN2][MAXN2][2];
           // cost used/cnt 0/1
pll check(string& s) {
    pll out = {0, 0};
    // Used, Cnt
    for(char c : s) {
        if(c == '(') {
            out.se++;
        } else if (c == ')') {
            if(out.se == 0) {
                out.fi++;
            } else {
                out.se--;
            }
        }
    }
    return out;
}

void add(int i, int j, int k, vector<string>& out) {
    for(string s1 : um[i][k][0]) {
        for(string s2 : um[j][k][1]) {
            string newS = s1 + s2;
            out.push_back(newS);
        }
    }
}

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> out; out.clear();
        for(int i = 0; i < MAXN2; i++) {
            for(int j = 0; j < MAXN2; j++) {
                um[i][j][0].clear();
                um[i][j][1].clear();
            }
        }

        ll midI = s.size()/2;
        for(int batch = 0; batch < 2; batch++) {
            ll startI = batch == 0 ? 0 : midI;
            ll endI = batch == 0 ? midI : s.size();
            ll nowLen = endI-startI;
            for(ll mask_ = 0; mask_ < (1ll << nowLen); mask_++) {
                ll mask = mask_;
                string nows = "";
                for(int i = 0; i < nowLen; i++) {
                    if(mask & 1) {
                        nows += s[startI+i];
                    }
                    mask = mask >> 1;
                }
                pll hasil = check(nows);
                if(batch == 0 && hasil.fi != 0) {continue;}
                if(batch == 1 && hasil.se != 0) {continue;}
                ll point = nowLen - (ll)nows.size();
                um[point][batch == 0 ? hasil.se : hasil.fi][batch].push_back(nows);
            }
        }

        for(ll cost = 0; cost <= s.size(); cost++) {
            for(int i = 0; i <= cost; i++) {
                int j = cost-i;
                for(int k = 0; k < MAXN2; k++) {
                    if(!um[i][k][0].empty() && !um[j][k][1].empty()) {
                        add(i, j, k, out);
                    }
                }
            }

            if(!out.empty()) {break ;}
        }
        sort(out.begin(), out.end());
        out.erase(unique(out.begin(), out.end()), out.end());
        return out;
    }
};