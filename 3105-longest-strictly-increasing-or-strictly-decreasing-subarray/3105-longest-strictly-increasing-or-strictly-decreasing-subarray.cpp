class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 0, inc = -1, dec = -1;
        for(int i=0;i<nums.size();i++) {
            int now = nums[i];
            if(inc == -1 || nums[i-1] >= now) {inc=i;}
            if(dec == -1 || nums[i-1] <= now) {dec=i;}
            mx=max(mx, max(i-inc+1,i-dec+1));
        }
        return mx;
    }
};