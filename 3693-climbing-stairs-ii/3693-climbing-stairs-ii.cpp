typedef long long ll;
const ll MAXN = 1e5 + 5;
ll dp[MAXN]; 
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        dp[0] = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=3;j++) {
                if(i-j < 0) {continue ;}
                ll hasil = dp[i-j]+costs[i-1]+j*j;
                if(j==1) {
                    dp[i] = hasil;
                    continue ;
                }
                dp[i] = min(dp[i], hasil);
            }
        }
        return dp[n];
    }
};