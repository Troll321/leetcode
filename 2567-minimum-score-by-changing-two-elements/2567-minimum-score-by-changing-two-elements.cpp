class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() <= 3) {
            return 0;
        }
        int n = nums.size();
        int ans = min(nums[n-1-2]-nums[0], min(nums[n-1]-nums[2], nums[n-1-1]-nums[1]));
        return ans;
    }
};