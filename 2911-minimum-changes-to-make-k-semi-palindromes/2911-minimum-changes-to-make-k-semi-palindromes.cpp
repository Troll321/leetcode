typedef long long ll;
const ll MAXN = 200 + 5;
const ll MAX = 1e9;

ll n, k, dp[MAXN][MAXN], carr[MAXN][MAXN];
string str;

ll cost(ll s, ll d) {
    if(s == d) {return MAX;}
    ll out = MAX;
    for(int div = 1; div < d-s+1; div++) {
        ll tmp = d-s+1;
        for(int i=s; i<=d; i++) {
            if((d-s+1) % div != 0) {tmp = MAX; continue ;}
            ll md = (i-s) % div;
            ll newId = s+d+1-div-i+2*md;
            tmp -= (str[i-1] == str[newId-1]);
        }
        // cout << "(" << s << ", " << d << ") : " << div << " = " << tmp << "!\n";
        out = min(out, tmp/2);
    }
    return out;
}

class Solution {
public:
    int minimumChanges(string s, int k_) {
        str = s;
        n = s.size();
        k = k_;
        // Hitung Cost
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                carr[i][j] = cost(i, j);
                // cout << "(" << i << ", " << j << ") = " << carr[i][j] << "\n";
            }
        }

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=0; j++) {
                dp[i][j] = MAX;
            }
        }
        dp[0][0] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=k; j++) {
                dp[i][j] = MAX;
                for(int w=j-1; w <= i-1; w++) {
                    dp[i][j] = min(dp[i][j], dp[w][j-1] + carr[w+1][i]);
                }
            }
        }
        return dp[n][k];
    }
};