typedef long long ll;
const ll MAXN = 1e5 + 5;
const ll MAXK = 15 + 5;
const ll MAX = 1e18;
ll n, x, val[MAXN], dp[MAXN][MAXK];

//          -bef +af
multiset<ll> bef, af;
ll mid = MAX, sum[2] = {0,0};

void insert(ll now) {
    if(mid == MAX) {mid = now; return ;}
    if(now <= mid) {
        bef.insert(-now);
        sum[0]+=now;
    } else {
        af.insert(now);
        sum[1]+=now;
    }
}

void balance() {
    while((ll)bef.size()-(ll)af.size() >= 2) {
        af.insert(mid);
        sum[1]+=mid;
        
        ll tmp = -(*bef.begin());
        mid = tmp;

        bef.erase(bef.begin());
        sum[0]-=tmp;
    }
    while((ll)bef.size()-(ll)af.size() <= -2) {
        bef.insert(-mid);
        sum[0]+=mid;
        
        ll tmp = *af.begin();
        mid = tmp;

        af.erase(af.begin());
        sum[1]-=tmp;
    }
}

class Solution {
public:
    long long minOperations(vector<int>& nums, int _x, int k) {
        n = nums.size();   
        x = _x;

        for(int i=0;i<=n;i++) {
            val[i] = 0;
            for(int j=0;j<=k;j++) {
                dp[i][j]=MAX;
            }
        }

        bef.clear(); af.clear();
        mid = MAX;
        sum[0] = 0;
        sum[1] = 0;

        for(int i=1;i<=x-1;i++){
            ll now = nums[i-1];
            insert(now);
            balance();
        }
        for(int i=1;i<=n-x+1;i++) {
            if(i>1) {
                ll todel = nums[i-1-1];
                auto it = bef.find(-todel);
                if(it==bef.end()) {
                    it = af.find(todel);
                    if(it == af.end()) {
                        if(bef.size() > af.size()) {
                            ll tmp = -(*bef.begin());
                            bef.erase(bef.begin());
                            sum[0]-=tmp;
                            mid=tmp;
                        } else {
                            ll tmp = *af.begin();
                            af.erase(af.begin());
                            sum[1]-=tmp;
                            mid=tmp;
                        }
                    } else {
                        sum[1] -= *it;
                        af.erase(it);
                    }
                } else {
                    sum[0] -= -(*it);
                    bef.erase(it);
                }
            }

            ll now = nums[i+x-2];
            insert(now);
            balance();
            val[i] = (mid*(ll)bef.size()-sum[0]) + (sum[1]-mid*(ll)af.size());
            // cout << now << " - " << -(*bef.begin()) << ", " << mid << ", " << *af.begin() << " | " << val[i] << "\n";
        }

        // DP
        for(int j=0;j<=k;j++) {
            for(int i=1;i<=n-x+1;i++){
                if(j==0) {dp[i][j] = 0; continue ;}
                dp[i][j] = dp[i-1][j];
                if(j == 1) {
                    dp[i][j] = min(dp[i][j], ((i-x) >= 1 ? dp[i-x][j-1] : 0ll) + val[i]);
                } else if (i-x >= 1) {
                    dp[i][j] = min(dp[i][j], dp[i-x][j-1]+val[i]);
                }
            }
        }
        return dp[n-x+1][k];
    }
};