#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MAXN = 5e4+5;

string str;
ll state[MAXN];
ll n;

vector<pll> adjl[MAXN];
// {v, weight}

class Solution {
public:
    int shortestPath(int n_, vector<vector<int>>& edges, string labels, int k) {
        n = n_;
        str=labels;
        for(int i=1;i<=n;i++) {
            adjl[i].clear();
            state[i] = -1;
        }
        for(int i=0;i<edges.size();i++) {
            adjl[edges[i][0]+1].push_back({edges[i][1]+1, edges[i][2]});
        }
        priority_queue<pair<ll, pll>> pq;
        // {-COST, {-Know, nxt}}
        while(!pq.empty()) {pq.pop();}
        pq.push({-0, {-1, 1}});
        while(!pq.empty()) {
            ll cost = -pq.top().fi;
            ll know = -pq.top().se.fi;
            ll node = pq.top().se.se;
            pq.pop();
            if(node == n) {
                return cost;
            }

            if(state[node] == -1 || state[node] > know) {
                state[node] = know;
                for(pll nxtp : adjl[node]) {
                    ll nxtc = str[nxtp.fi-1];
                    ll nxtk = nxtc == str[node-1] ? know+1 : 1;
                    if(nxtk > k) {continue ;}
                    pq.push({-(nxtp.se + cost), {-nxtk, nxtp.fi}});
                }
            }
        }
        return -1;
    }
};