typedef long long ll;
const ll MAXN = 1e3 + 5;
vector<ll> vec[MAXN][MAXN];

ll n, m;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                vec[i][j].clear();
                ll now = grid[i-1][j-1];
                if(i==1&&j==1) {
                    vec[i][j].push_back(now);
                    continue ;
                }
                for(int k = -1; k <= 0; k++) {
                    for(int l = -1; l <= 0; l++) {
                        if(l==k) {continue;}
                        if(i+k < 1 || j+l < 1) {continue;}
                        for(ll x : vec[i+k][j+l]) {
                            vec[i][j].push_back(now ^ x);
                        }
                    }
                }
                sort(vec[i][j].begin(), vec[i][j].end());
                vec[i][j].erase(unique(vec[i][j].begin(), vec[i][j].end()), vec[i][j].end());
            }
        }
        return vec[n][m][0];
    }
};