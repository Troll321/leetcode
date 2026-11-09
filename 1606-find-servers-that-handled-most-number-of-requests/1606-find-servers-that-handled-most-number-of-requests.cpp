#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN = 1e5 + 5;
ll k;
ll cnt[MAXN], tts[MAXN], fen[MAXN];

void add(ll idx, ll x) {
    for(int i = idx; i <= k; i += (i&-i)) {
        fen[i] += x;
    }
}

ll get(ll idx) {
    ll out = 0;
    for(int i = idx; i > 0; i -= (i&-i)) {
        out += fen[i];
    }
    return out;
}

ll getRange(ll l, ll r) {
    return get(r)-get(l-1);
}

class Solution {
public:
    vector<int> busiestServers(int k_, vector<int>& arrival, vector<int>& load) {
        k = k_;
        for(int i=1;i<=k;i++) {
            cnt[i]=0;
            fen[i]=0;
        }

        for(int i=1;i<=k;i++) {
            add(i,1);
        }

        vector<pll> times = {};
        times.clear();
        for(int i=0; i<arrival.size();i++) {
            tts[i+1] = 0;
            times.push_back({arrival[i], i+1});
            times.push_back({arrival[i]+load[i], -(i+1)});
        }
        sort(times.begin(), times.end());


        ll mx=0;
        for(pll nowp : times) {
            ll id = nowp.se;

            if(id < 0) {
                // Free tts[-id] (add to DS)
                if(tts[-id] == 0) {continue ;}
                add(tts[-id], 1);
            } else {
                if(getRange(1, k) == 0) {continue ;}
                // X = (id-1)%k + 1;
                ll x = (id-1)%k + 1ll;
                if(getRange(x,x) == 0) {
                    if(getRange(x, k) != 0) {
                        // Kalo ga ada, cari yg lebih besar paling kecil
                        ll tmpans=0, l=x+1, r=k, mid;
                        while(l<=r) {
                            mid=(l+r)/2;
                            ll hasil = getRange(x, mid);
                            if(hasil >= 1) {
                                r = mid-1;
                                tmpans = mid;
                            } else {
                                l = mid+1;
                            }
                        }
                        x = tmpans;
                    } else {
                        // Else cari yg paling kecil
                        ll tmpans=0, l=1, r=x-1, mid;
                        while(l<=r) {
                            mid=(l+r)/2;
                            ll hasil = getRange(1, mid);
                            if(hasil >= 1) {
                                r = mid-1;
                                tmpans = mid;
                            } else {
                                l = mid+1;
                            }
                        }
                        x = tmpans;
                    }
                }
                // Assign tts[id] = X
                tts[id] = x;
                add(x, -1);
                mx = max(mx, ++cnt[x]);
            }
        }
        vector<int> ans = {};
        ans.clear();
        for(int i=1;i<=k;i++) {
            if(cnt[i] == mx) {ans.push_back(i-1);}
        }
        return ans;
    }
};