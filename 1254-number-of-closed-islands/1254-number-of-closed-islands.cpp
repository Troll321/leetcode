#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN = 100 + 5;
ll parent[MAXN*MAXN], val[MAXN*MAXN];

int n, m, ans = 0;

ll conv(pll x) {
    return (x.fi-1ll)*m + x.se;
}

void build() {
    ans = n*m;
    for(int i = 1; i <= n*m; i++) {
        parent[i] = i;
        val[i] = 1;
    }
}

ll find(ll x) {
    if(parent[x] == x) {return x;}
    parent[x] = find(parent[x]);
    return parent[x];
}

bool isBound(pll x) {
    return (x.fi == 1 || x.fi == n || x.se == 1 || x.se == m);
}

void join(pll a_, pll b_) {
    ll a = conv(a_), b = conv(b_);
    ll x = find(a);
    ll y = find(b);
    if(x == y) {return ;}
    if(isBound(a_) || isBound(b_) || val[x] == 0 || val[y] == 0) {
        ans -= val[x] + val[y];
        val[x] = 0;
        val[y] = 0;
    } else {
        ans--;
        val[x] = 0;
    }
    parent[x] = y;
}

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        build();

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(grid[i-1][j-1] == 1) {
                    val[conv({i, j})] = 0; ans--;
                    continue ;
                }
                if(isBound({i, j})) {
                    ll tmp = find(conv({i, j}));
                    ans -= val[tmp];
                    val[tmp] = 0;
                }

                for(int k = 0; k <= 1; k++) {
                    for(int l = 0; l <= 1; l++) {
                        if(l == k) {continue ;}
                        if(i+k <= n && j+l <= m && grid[i+k-1][j+l-1] == 0) {
                            join({i, j}, {i+k, j+l});
                        }
                    }
                }
            }
        }

        return ans;
    }
};