#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN = 1e5 + 5;
const ll MAX = 1e10;
const ll MOD = 1e9 + 7;
const ll BASE = 911382323;

ll ans = MAX, n;

ll hashArr[MAXN], base[MAXN];
unordered_map<ll, ll> occr;
bool solve(ll len) {
    occr.clear();
    for(int i = len; i <= n; i++) {
        ll nowHash = hashArr[i] - hashArr[i-len]*base[len]%MOD;
        nowHash = ((nowHash % MOD) + MOD) % MOD;
        occr[nowHash]++;
    }
    for(pll now : occr) {
        if(now.se == 1) {return true;}
    }
    return false;
}

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        ans = n;
        hashArr[0] = 0;
        base[0] = 1;
        for(ll i = 1; i <= n; i++) {
            ll now = nums[i-1];
            hashArr[i] = (hashArr[i-1]*BASE%MOD + now) % MOD;
            base[i] = base[i-1]*BASE%MOD;
        }

        ll l = 1, r = n, mid;
        while(l <= r) {
            mid = (l+r)/2;
            bool hasil = solve(mid);
            if(hasil) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};