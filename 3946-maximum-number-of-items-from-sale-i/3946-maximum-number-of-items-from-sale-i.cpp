typedef long long ll;
const ll MAXN = 1500 + 5;
ll price[MAXN], val[MAXN], dp[MAXN];
ll n, budget;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget_) {
        memset(dp, 0, sizeof(dp));
        n = items.size();   
        budget = budget_;
        for(int i = 1; i <= n; i++) {
            price[i] = items[i-1][1];
            val[i] = 1;
            for(int j = 1; j <= n; j++) {
                if(i == j) {continue ;}
                val[i] += ((items[j-1][0] % items[i-1][0]) == 0);
            }
        }

        for(int i = 1; i <= 2*n; i++) {
            if(i <= n) {
                for(int j = budget; j >= 1; j--) {
                    dp[j] = max(dp[j], (j-price[i]) >= 0 ? dp[j-price[i]]+val[i] : 0ll);
                }
            } else {
                for(int j = 1; j <= budget; j++) {
                    dp[j] = max(dp[j], (j-price[i-n]) >= 0 ? dp[j-price[i-n]]+1ll : 0ll);
                }
            }
        }
        return dp[budget];
    }
};