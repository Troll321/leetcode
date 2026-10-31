typedef long long ll;
const ll MAXN = 500 + 5;
const ll MOD = 1e9 + 7;

ll dp[MAXN][MAXN][2];
// i, j, kiri=0/kanan=1

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(i==1&&j==1) {dp[i][j][0]=1;dp[i][j][1]=0; continue ;}
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                if(j > 1) {
                    dp[i][j][0] += dp[i][j-1][1];
                    if(grid[i-1][j-1-1] != 1) {
                        dp[i][j][0] += dp[i][j-1][0];
                    }
                }
                dp[i][j][0] %= MOD;
                if(i > 1) {
                    dp[i][j][1] += dp[i-1][j][0];
                    if(grid[i-1-1][j-1] != 1) {
                        dp[i][j][1] += dp[i-1][j][1];
                    }
                }
                dp[i][j][1] %= MOD;
            }
        }
        return (dp[n][m][0]+dp[n][m][1])%MOD;
    }
};