typedef long long ll;
const ll MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll LOG = 30;
const ll MAXLOG = LOG + 5;

ll cntArr[MAXLOG];

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        memset(cntArr, 0, sizeof(cntArr));
        for(ll now : nums) {
            ll idx = 0;
            while(now > 0) {
                cntArr[idx] += (now&1);
                idx++;
                now = now >> 1;
            }
        }

        ll ans = 0;
        for(int i = 1; i <= k; i++) {
            ll tmp = 0;
            for(int j = 0; j <= LOG; j++) {
                if(cntArr[j] >= i) {
                    tmp += (1ll << j);
                }
            }
            tmp %= MOD;
            ans += tmp*tmp % MOD;
            ans %= MOD;
        }

        return ans;
    }
};