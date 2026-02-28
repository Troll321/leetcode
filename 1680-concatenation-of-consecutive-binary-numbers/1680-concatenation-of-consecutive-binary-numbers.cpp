typedef long long ll;
const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    if (b == 0) {return 1ll;}
    ll tmp = binpow(a, b >> 1);
    return tmp * tmp % MOD * (b&1 ? a % MOD : 1ll);
}

ll mylen(ll x) {
    ll out = 0;
    while(x > 0) {
        out++;
        x = x >> 1;
    }

    return out;
}

class Solution {
public:
    int concatenatedBinary(int n) {
        ll out = 0, cnt = 0;
        for (int i = n; i >= 1; i--) {
            out += binpow(2, cnt) * i % MOD;
            out %= MOD;
            cnt += mylen(i);
        }
        return out;
    }
};