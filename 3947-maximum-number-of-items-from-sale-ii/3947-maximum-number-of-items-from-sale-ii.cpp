typedef long long ll;
const ll MAXN = 1e5 + 5;
ll n, budget, ans, freq[MAXN];

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[1] == b[1]) {return a[0] < b[0];}
    return a[1] < b[1];
}

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget_) {
        ans = 0;
        n = items.size();
        budget = budget_;
        sort(items.begin(), items.end(), cmp);

        ll mnp = items[0][1];

        for(int i = 0; i<=n; i++) {freq[i]=0;}
        for(int i = 0; i<items.size(); i++) {
            ll nowF = items[i][0];
            for(int j=1;j*j<=nowF; j++) {
                if(nowF % j == 0) {
                    freq[j]++;
                    if(j != (nowF/j)) {freq[nowF/j]++;}
                }
            }
        }


        for(int i = 0; i<items.size(); i++) {
            ll nowF = items[i][0], nowP = items[i][1];
            ll freqn = freq[nowF]-1;

            if(freqn == 0) {continue ;}
            if(mnp*2ll <= nowP) {break ;}
            ll mxf = min(freqn, budget / nowP);
            budget -= mxf*nowP;
            ans += mxf*2ll;
            freqn -= mxf;
            mxf = 0;
        }
        ans += budget/mnp;
        budget %= mnp;
        return ans;
    }
};