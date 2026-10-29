typedef long long ll;
const ll MAXN = 5e4 + 5;

struct Node {
    ll cnt[26];
    Node() {
        for(int i=0;i<26;i++) {cnt[i]=0;}
    }
};

Node merge(Node a, Node b) {
    Node out;
    for(int i=0;i<26;i++) {
        out.cnt[i] = a.cnt[i]+b.cnt[i];
    }
    return out;
}

string str;
Node seg[4*MAXN], netral;
void build(ll pos, ll l, ll r) {
    seg[pos] = netral;
    if(l==r){
        return ;
    }
    ll mid = (l+r)/2;
    build(pos*2, l, mid);
    build(pos*2+1, mid+1, r);
}

Node query(ll pos, ll l, ll r, ll a, ll b) {
    if(r < a || l > b) {
        return netral;
    }
    if(a <= l && r <= b) {
        return seg[pos];
    }
    ll mid=(l+r)/2;
    return merge(query(pos*2, l, mid, a, b), query(pos*2+1, mid+1, r, a, b));
}

void update(ll pos, ll l, ll r, ll idx, char co, char cn) {
    if(r < idx || l > idx) {
        return ;
    }
    if(idx <= l && r <= idx) {
        if(co != '\0') {
            seg[pos].cnt[co-'a']--;
        }
        seg[pos].cnt[cn-'a']++;
        return ;
    }

    ll mid=(l+r)/2;
    update(pos*2, l, mid, idx, co, cn);
    update(pos*2+1, mid+1, r, idx, co, cn);
    seg[pos] = merge(seg[pos*2], seg[pos*2+1]);
}


ll n, lng[MAXN], parr[MAXN], depth[MAXN];
vector<ll> adjl[MAXN];
void precomp(ll now, ll par) {
    depth[now] = depth[par]+1;
    parr[now] = par;
    for(ll nxt : adjl[now]) {
        if(nxt == par){continue ;}
        precomp(nxt, now);
        lng[now] = max(lng[now], lng[nxt]);
    }
    lng[now]++;
}

ll segIdx[MAXN], root[MAXN];
ll cnt = 1;
void hld(ll now, ll par, ll heavyRoot) {
    segIdx[now] = cnt++;
    update(1,1,n,segIdx[now],'\0',str[now-1]);

    if(heavyRoot != -1) {root[now] = heavyRoot;}
    else {root[now] = now;}

    ll mx = -1, nxtHeavy = -1;
    for(ll nxt : adjl[now]) {
        if(nxt == par){continue ;}
        if(lng[nxt] > mx) {
            nxtHeavy = nxt;
            mx = lng[nxt];
        }
    }

    if(nxtHeavy == -1) {return ;}

    hld(nxtHeavy, now, root[now]);
    for(ll nxt : adjl[now]) {
        if(nxt == par || nxt == nxtHeavy){continue ;}
        hld(nxt, now, -1);
    }
}

class Solution {
public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s_, vector<string>& queries) {
        vector<bool> ansvec;
        ansvec.clear();
        str = s_;
        n = n_;
        for(int i=1;i<=n;i++) {
            adjl[i].clear();
            lng[i] = 0;
            depth[i] = 0;
        }
        for(int i=0;i<edges.size();i++) {
            ll a = edges[i][0]+1, b = edges[i][1]+1;
            adjl[a].push_back(b);
            adjl[b].push_back(a);
        }
        build(1,1,n);
        precomp(1, 1);
        cnt = 1;
        hld(1, 1, -1);
        for(string nowq : queries) {
            if(nowq[0] == 'u') {
                // Update
                string nodeS = "";
                char c;
                int i = 7;
                while(nowq[i] != ' ') {
                    nodeS += nowq[i];
                    i++;
                }
                i++;
                c = nowq[i];
                ll node = stoi(nodeS) + 1;
                update(1,1,n,segIdx[node],str[node-1],c);
                str[node-1]=c;
            } else {
                // Query
                string nodeAS = "", nodeBS = "";
                int i = 6;
                while(nowq[i] != ' ') {
                    nodeAS += nowq[i];
                    i++;
                }
                i++;
                while(i<nowq.size()) {
                    nodeBS += nowq[i];
                    i++;
                }
                ll nodeA = stoi(nodeAS) + 1, nodeB = stoi(nodeBS) + 1;

                Node nowAns;
                while(root[nodeA] != root[nodeB]) {
                    // Up par
                    if(depth[root[nodeA]] > depth[root[nodeB]]) {
                        nowAns = merge(nowAns, query(1,1,n,segIdx[root[nodeA]],segIdx[nodeA]));
                        nodeA = parr[root[nodeA]];
                    } else {
                        nowAns = merge(nowAns, query(1,1,n,segIdx[root[nodeB]],segIdx[nodeB]));
                        nodeB = parr[root[nodeB]];
                    }
                }
                ll ida = segIdx[nodeA], idb = segIdx[nodeB];
                nowAns = merge(nowAns, query(1,1,n,min(ida,idb),max(ida,idb)));
                ll nState = 2;
                for(int i=0;i<26;i++){
                    nState -= nowAns.cnt[i]%2;
                }
                ansvec.push_back(nState > 0 ? true : false);
            }
        }
        return ansvec;
    }
};