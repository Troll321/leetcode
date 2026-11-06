typedef long long ll;
const ll MAXN = 1e6 + 5;
ll n, mxt, x;

ll fen[MAXN], lst[MAXN];
void add(ll idx, ll x) {
    if(idx == 0) {return ;}
    fen[idx]+=x;
}
ll get(ll idx) {
    return fen[idx];
}
void resolve() {
    fen[0] = 0;
    for(int i = 1; i <= mxt; i++) {
        fen[i] += fen[i-1];
    }
}

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

class Solution {
public:
    vector<int> countServers(int n_, vector<vector<int>>& logs, int x_, vector<int>& queries) {
        n = n_;
        x = x_;
        for(int i = 1; i <= n; i++) {
            lst[i] = 0;
        }

        sort(logs.begin(), logs.end(), cmp);

        mxt=logs.back()[1];
        for(ll now:queries) {mxt=max(now,mxt);}

        for(int i = 1; i <= mxt; i++) {
            fen[i] = 0;
        }

        for(int i=0; i<logs.size();i++) {
            ll id = logs[i][0];
            ll t = logs[i][1];
            ll tlow = max(t, lst[id]+1ll);
            ll thigh = min(mxt, t+x);
            add(tlow, 1);
            add(thigh+1, -1);
            lst[id] = thigh;
        }

        resolve();

        vector<int> answer;
        answer.clear();
        for(ll now:queries) {
            answer.push_back(n-get(now));
        }
        return answer;
    }
};