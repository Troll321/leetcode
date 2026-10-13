typedef long long ll;

bool cmp(ll a, ll b) {
    return abs(a) < abs(b);
}

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        ll n = nums.size();
        ll mn = n/2;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if(i <= mn) {
                ans -= nums[i-1]*nums[i-1];
            } else {
                ans += nums[i-1]*nums[i-1];
            }
        }
        return ans;
    }
};