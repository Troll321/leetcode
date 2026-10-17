#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll MAXN = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll SET = 1;
const ll PLUS = 2;
const ll NEG = 3;

struct Node {
    ll A = 0, A_ = 0, i = 0, ex = 0, I = 0;

    Node() {
        A = 0, A_ = 0, i = 0, ex = 0, I = 0;
    }
};

Node merge(Node a, Node b) {
    Node out;
    out.A = a.A + b.A;
    out.A_ = a.A_ + b.A_;
    out.i = a.i + b.i;
    out.ex = a.ex + b.ex;
    out.I = a.I + b.I;
    return out;
}

Node seg[4*MAXN], lazy[4*MAXN];
queue<ll> idx[MAXN];
vector<ll> awalan;
bool visited[MAXN];

Node netral;
ll n;

void applyLazy(ll pos, ll l, ll r) {
    seg[pos].A_ += lazy[pos].A_*seg[pos].A;
    seg[pos].i += lazy[pos].i*(r-l+1ll);
    seg[pos].I += lazy[pos].I*seg[pos].ex;
    
    if(l == r) {
        lazy[pos].A_ = 0;
        lazy[pos].i = 0;
        lazy[pos].I = 0;
        return ;
    }
    if(lazy[pos].A_ != 0){
        lazy[pos*2].A_ += lazy[pos].A_;
        lazy[pos*2+1].A_ += lazy[pos].A_;
    }
    if(lazy[pos].i != 0){
        lazy[pos*2].i += lazy[pos].i;
        lazy[pos*2+1].i += lazy[pos].i;
    }
    if(lazy[pos].I != 0) {
        lazy[pos*2].I += lazy[pos].I;
        lazy[pos*2+1].I += lazy[pos].I;
    }
    lazy[pos].A_ = 0;
    lazy[pos].i = 0;
    lazy[pos].I = 0;
}

Node get(ll pos, ll l, ll r, ll a, ll b) {
    if(l > b || r < a) {
        return netral;
    }
    applyLazy(pos, l, r);
    if(a <= l && r <= b) {
        return seg[pos];
    }
    ll mid = (l+r)/2;
    return merge(get(pos*2, l, mid, a, b), get(pos*2+1, mid+1, r, a, b));
}

void update(ll pos, ll l, ll r, ll a, ll b, pll upd) {
    applyLazy(pos, l, r);
    if(l > b || r < a) {
        return ;
    }
    if(a <= l && r <= b) {
        // Set lazy and value
        switch(upd.fi) {
            case SET:
                if(upd.se == -1) {
                    seg[pos].A = 0;
                    seg[pos].A_ = 0;
                    seg[pos].ex = 0;
                    seg[pos].I = 0;
                } else {
                    seg[pos].A = upd.se;
                    seg[pos].A_ = upd.se*seg[pos].i;
                    seg[pos].ex = 1;
                    seg[pos].I = seg[pos].i;
                }
            break;
            case PLUS:
                lazy[pos].A_++;
                lazy[pos].i++;
                lazy[pos].I++;
                applyLazy(pos, l, r);
                // seg[pos].A_ += seg[pos].A;
                // seg[pos].i += r-l+1ll;
                // seg[pos].I += seg[pos].ex;
            break;
            case NEG:
                lazy[pos].A_--;
                lazy[pos].i--;
                lazy[pos].I--;
                applyLazy(pos, l, r);
                // seg[pos].A_ -= seg[pos].A;
                // seg[pos].i -= r-l+1ll;
                // seg[pos].I -= seg[pos].ex;
            break;
        }
        return ;
    }
    ll mid = (l+r)/2;
    update(pos*2, l, mid, a, b, upd);
    update(pos*2+1, mid+1, r, a, b, upd);
    seg[pos] = merge(seg[pos*2], seg[pos*2+1]);
}

void insertSeg(ll realIdx, ll currentPos) {
    update(1, 1, n, realIdx, realIdx, make_pair(SET, realIdx));
    if(realIdx-1 >= 1) {
        update(1, 1, n, 1, realIdx-1, make_pair(PLUS, 0));
    }
}

void eraseSeg(ll realIdx) {
    update(1, 1, n, realIdx, realIdx, make_pair(SET, -1));
    if(realIdx-1 >= 0) {
        update(1, 1, n, 1, realIdx-1, make_pair(NEG, 0));
    }
}

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
        memset(visited, 0, sizeof(visited));
        awalan.clear();
        ll ans = 0, unq = 0;
        n = nums.size();

        // Precompute
        for(int i = 1; i <= n; i++) {
            ll now = nums[i-1];
            idx[now].push(i);
            if(!visited[now]) {
                awalan.push_back(i);
                visited[now] = true;
                unq++;
            }
        }

        for(ll now : awalan) {
            insertSeg(now, 0);
        }

        for(ll i = 1; i <= n; i++) {
            Node sums = get(1, 1, n, 1, n);
            sums.A %= MOD;
            sums.A_ %= MOD;
            ll bef = ans;
            ans += (n-i+1ll)*(unq*unq % MOD) % MOD;
            ans %= MOD;
            ans += 2ll*sums.A_ % MOD;
            ans %= MOD;
            ans += 2ll*i*(unq*unq % MOD) % MOD;
            ans %= MOD;
            ans += (sums.A*(1ll-2ll*unq) % MOD - i*unq % MOD - i*(unq*(unq-1ll) % MOD) % MOD) % MOD;
            ans = ((ans%MOD)+2ll*MOD) % MOD;

            ll now = nums[i-1];
            idx[now].pop();
            eraseSeg(i);
            unq--;
            if(!idx[now].empty()) {
                unq++;
                insertSeg((ll)idx[now].front(), i);
            }
        }

        return ans;
    }
};