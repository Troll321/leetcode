typedef long long ll;
const ll MAX = 1e9;

ll solve(ll x, vector<int>& nums) {
    ll out=0;
    for(ll now:nums){out += abs(now-x);}
    return out;
}

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll n = nums.size();
        return min(
            solve(nums[(n-1)/2], nums),
            solve(nums[n/2], nums)
        );
    }
};