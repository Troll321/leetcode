typedef long long ll;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll n = nums1.size();
        vector<ll> nowv;
        nowv.clear();
        for(int i = 0; i < n; i++) {
            nowv.push_back(abs(nums1[i]-nums2[i]));
        }
        sort(nowv.begin(), nowv.end(), greater<ll>());
        ll k = k1+k2;
        ll prefs = 0, limit = 0, sisa = 0;
        for(ll i = 0; i < n; i++) {
            prefs += nowv[i];
            if(i == 0) {continue ;}
            ll now = nowv[i];
            if(prefs - now*(i+1ll) <= k) {
                limit = i;
                sisa = k - (prefs - now*(i+1ll));
            }
        }

        if(prefs <= k) {return 0;}

        // Process until limit
        for(ll i = 0; i <= limit; i++) {
            nowv[i] = nowv[limit] - sisa/(limit+1ll) + (i < (sisa % (limit+1ll)) ? -1ll : 0);
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += nowv[i]*nowv[i];
        }
        return ans;
    }
};