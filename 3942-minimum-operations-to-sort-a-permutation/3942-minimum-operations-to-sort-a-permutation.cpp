class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Cek bisa ga
        int n = nums.size();
        if(n == 1) {return 0;}
        int bef = -1;
        int cnt[2] = {0,0};
        int id[2] = {0,0};
        // {inc, dec}
        int flag = -1;
        for(int i = 0; i < 2*n; i++) {
            int now = nums[i%n];
            if(i<n) {
                if(now == 0) {id[0] = i+1;}
                if(now == n-1) {id[1] = i+1;}
            }
            if(i == 0) {cnt[0]=0; cnt[1]=0;}
            else if(bef < now) {cnt[1]=0;}
            else if(bef > now) {cnt[0]=0;}
            bef = now;
            cnt[0]++;
            cnt[1]++;
            if(cnt[0] == n) {flag=0; break;}
            if(cnt[1] == n) {flag=1; break;}
        }
        if(flag == -1) {return -1;}
        return min(id[flag]-1+flag, n-id[flag]+3-flag);
    }
};