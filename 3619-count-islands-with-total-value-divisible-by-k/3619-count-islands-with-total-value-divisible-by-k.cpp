#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN = 1e3 + 5;
ll n, m, k, ans;

ll parent[MAXN*MAXN], sum[MAXN*MAXN];

ll conv(pll x) {
    return (x.fi-1)*m + x.se;
}

void build(vector<vector<int>>& grid) {
    pll coor = {0,0};
    ans = 0;
    for(int i = 1; i <= n*m; i++) {
        parent[i] = i;
        sum[i] = grid[coor.fi][coor.se];
        if(sum[i] != 0 && sum[i] % k == 0) {ans++;}
        if(++coor.se == m) {
            coor.se = 0;
            coor.fi++;
        }
    }
}

ll find(ll x) {
    if(parent[x] == x) {return x;}
    parent[x] = find(parent[x]);
    return parent[x];
}

void join(pll x, pll y) {
    ll a = find(conv(x)), b = find(conv(y));
    if(a == b) {return ;}
    ans -= (sum[a] % k == 0) + (sum[b] % k == 0);
    sum[b] += sum[a];
    parent[a] = b;
    ans += (sum[b] % k == 0);
}

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k_) {
        n = grid.size();
        m = grid[0].size();
        k = k_;
        build(grid);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(grid[i-1][j-1] == 0) {continue ;}
                for(int w = 0; w <= 1; w++) {
                    for(int l = 0; l <= 1; l++) {
                        if(l==w) {continue ;}
                        if(i+w > n || j+l > m) {continue ;}
                        if(grid[i+w-1][j+l-1] == 0) {continue ;}
                        join({i,j}, {i+w, j+l});
                    }
                }
            }
        }
        return ans;
    }
};