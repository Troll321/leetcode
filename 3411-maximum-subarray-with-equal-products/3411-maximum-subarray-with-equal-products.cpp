typedef long long ll;
const ll MAXN = 100 + 5;
ll gfpb(ll a, ll b) {
    if(b == 0) {return a;}
    return gfpb(b, a % b);
}
ll glcm(ll a, ll b) {return a/gfpb(a,b)*b;}
class Solution {
public:
    int maxLength(vector<int>& nums) {
        ll ans = 0;
        for(ll i = 0; i<nums.size();i++) {
            ll prod = -1;
            ll lcm = -1, fpb = -1;
            for(ll j = i+1; j<nums.size(); j++) {
                for(int k=i; k<=j; k++) {
                    if(k==i) {
                        prod = nums[k];
                        lcm = nums[k];
                        fpb = nums[k];
                        continue ;
                    }
                    prod *= nums[k];
                    if(prod > (ll)10000) {
                        prod = 0;
                        break ;
                    }
                    fpb = gfpb(fpb, nums[k]);
                    lcm = glcm(lcm, nums[k]);
                }
                if(prod == lcm * fpb){ans = max(ans, j-i+1ll);}
            }
        }
        return (int)ans;
    }
};