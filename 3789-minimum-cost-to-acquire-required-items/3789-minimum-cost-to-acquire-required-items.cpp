typedef long long ll;
class Solution {
public:
    ll minimumCost(ll cost1, ll cost2, ll costBoth, ll need1, ll need2) {
        ll ans = 0;
        if(costBoth > cost1 + cost2) {
            ans = need1*cost1 + need2*cost2;
        } else {
            ll mn = min(need1, need2);
            ans = costBoth*mn;
            ll butuh = need1 == mn ? need2-mn : need1-mn;
            ll cButuh = need1 == mn ? cost2 : cost1;
            if(cButuh > costBoth) {
                ans += butuh*costBoth;
            } else {
                ans += butuh*cButuh;
            }
        }
        return ans;
    }
};