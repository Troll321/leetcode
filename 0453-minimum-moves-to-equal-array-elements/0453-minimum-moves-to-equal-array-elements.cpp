class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = nums[0];
        for (int x:nums){mn=min(x,mn);}
        for (int x:nums){ans+=x-mn;}
        return ans;
    }
};