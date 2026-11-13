#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN = 1e5 + 5;
const ll MAX = 1e10;

void print(vector<pll>& vec) {
    cout << "-- ";
    for(pll ks:vec) {
        cout << ks.fi << " " << ks.se << " | ";
    } cout << "--\n";
}

ll n;
ll fen[3][MAXN], pref[MAXN];
// [0: hi, 1: Iihi, 2: Ii+1_hi]

void update(ll t, ll idx, ll x) {
    if(idx <= 0) {return ;}
    for(int i=idx;i<=n;i+=(i&-i)) {
        fen[t][i] += x;
    }
}
ll get(ll t, ll idx) {
    ll out = 0;
    for(int i=idx;i>0;i-=(i&-i)) {
        out += fen[t][i];
    }
    return out;
}
ll getFenRange(ll t, ll l, ll r) {
    if(l > r) {swap(l, r);}
    return get(t,r)-get(t,l-1);
}
ll getPrefRange(ll l, ll r) {
    if(l > r) {swap(l, r);}
    return pref[r]-(l-1 < 1 ? 0 : pref[l-1]);
}

vector<pll> vec;
// {Idx, hi}

ll toFen(ll x) {
    return vec.size()-x;
}

ll calc(ll i, ll r) {
    ll L = upper_bound(vec.rbegin(), vec.rend(), make_pair(r,MAX))-vec.rbegin();
    pll lstV = vec[vec.size()-L]; 
    ll out = 0;
    if(L > 1) {
        out += getFenRange(2,toFen(1),toFen(L-1))-getFenRange(1,toFen(1),toFen(L-1))-getPrefRange(i,lstV.fi-1);
    }
    out += lstV.se*(r-lstV.fi+1) - getPrefRange(lstV.fi, r);
    return out;
}

class Solution {
public:
    ll countNonDecreasingSubarrays(vector<int>& nums, ll k) {
        ll ans = 0;
        n = nums.size();
        pref[0] = 0;
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i] + nums[i];
            for(int j=0;j<3;j++){
                fen[j][i]=0;
            }
        }

        vec.clear();
        for(int i=n;i>=1;i--){
            ll now = nums[i-1];
            // Maintain Vec (+ have to maintain fen!)
            if(vec.empty()) {
                vec.push_back({i, now});
            } else {
                while(!vec.empty() && now >= vec.back().se) {
                    pll tmp = vec.back();
                    vec.pop_back();
                    if(!vec.empty()) {
                        update(0, vec.size(), -tmp.se);
                        update(1, vec.size(), -tmp.fi*tmp.se);
                        update(2, vec.size(), -tmp.se*vec.back().fi); 
                    }
                }
                if(!vec.empty()) {
                    update(0, vec.size(), now);
                    update(1, vec.size(), i*now);
                    update(2, vec.size(), now*vec.back().fi);
                }
                vec.push_back({i, now});
            }

            ll l = i, r = n, mid, tmpo = 0;
            while(l <= r) {
                mid=(l+r)/2;
                ll hasil = calc(i, mid);
                if(hasil <= k) {
                    tmpo = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            ans += tmpo-i+1;
        }

        return ans;
    }
};