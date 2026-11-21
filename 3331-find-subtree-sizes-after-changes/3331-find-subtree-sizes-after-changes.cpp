typedef long long ll;
const ll MAXN = 1e5 + 5;
vector<ll> adjl[MAXN];
ll n, sym[MAXN];
vector<int> ans;

ll sub[MAXN];
vector<ll> passed[26];
void dfs(ll now, ll par) {
    passed[sym[now]].push_back(now);
    sub[now]++;
    for(ll nxt:adjl[now]) {
        if(nxt == par) {continue ;}
        dfs(nxt, now);
        if(passed[sym[nxt]].empty()) {
            sub[now] += sub[nxt];
        }
    }

    passed[sym[now]].pop_back();
    if(!passed[sym[now]].empty()) {
        sub[passed[sym[now]].back()] += sub[now];
    }
}

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s)  {
        n = parent.size();
        ans.clear();
        for(int i = 1; i<=n; i++) {
            adjl[i].clear();
            sub[i] = 0;
        }
        for(int j=0;j<26;j++) {passed[j].clear();}
        for(int i = 1; i<=n; i++) {
            sym[i] = s[i-1]-'a';
            if(i>1){
                adjl[i].push_back(parent[i-1]+1);
                adjl[parent[i-1]+1].push_back(i);
            }
        }

        dfs(1,1);

        for(int i = 1; i<=n; i++) {
            ans.push_back(sub[i]);
        }
        return ans;
    }
};