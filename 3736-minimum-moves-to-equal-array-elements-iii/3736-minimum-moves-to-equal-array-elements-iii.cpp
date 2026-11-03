class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0,sm=0;
        for(int x:nums){sm+=x;mx=max(mx,x);}
        return mx*nums.size()-sm;
    }
};