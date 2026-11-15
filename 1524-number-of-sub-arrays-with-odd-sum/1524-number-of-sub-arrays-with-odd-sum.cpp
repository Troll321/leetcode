typedef long long ll;
const ll MOD = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll odd = 0, even = 1, sm = 0, ans = 0;
        for(int now:arr){
            sm += now%2;
            sm%=2;
            if(sm == 0) {ans+=odd%MOD;even++;}
            else {ans+=even%MOD;odd++;}
            ans%=MOD;
        }
        return ans;
    }
};