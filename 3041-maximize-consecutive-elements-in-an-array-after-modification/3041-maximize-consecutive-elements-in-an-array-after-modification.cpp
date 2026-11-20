typedef long long ll;
const ll MAXN = 1e6 + 5;

ll cnt[MAXN], dp[MAXN][2];

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        ll mx = 0;
        for(ll now:nums) {cnt[now]++; mx=max(mx,now);}
        ll ans = -1;

        for(int i=1;i<=mx+1;i++){
            if(cnt[i]>=1) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + 1;
            }
            if(cnt[i-1]>=1) {
                dp[i][1] = dp[i-1][1]+1;
            }
            if(cnt[i-1]>=2) {
                dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }

        return ans;
    }
};