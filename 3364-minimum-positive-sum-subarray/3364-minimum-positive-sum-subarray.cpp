class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
        int ans = -1;
        for(int sz=l;sz<=r;sz++) {
            for(int i=0;i<nums.size()-sz+1;i++){
                int hasil = nums[i+sz-1]-(i==0?0:nums[i-1]);
                if(hasil>0) {
                    ans = ans==-1?hasil:min(ans, hasil);
                }
            }
        }
        return ans;
    }
};