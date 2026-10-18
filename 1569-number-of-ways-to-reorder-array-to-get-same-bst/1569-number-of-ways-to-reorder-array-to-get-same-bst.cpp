typedef long long ll;
const ll MOD = 1e9+7;
const ll MAXFAC = 5e3;
ll fac[MAXFAC + 5];
bool facpopul = false;

void precomp() {
    if(!facpopul) {
        facpopul = true;
        fac[0] = 1;
        for(ll i = 1; i <= MAXFAC; i++) {
            fac[i] = fac[i-1]*i % MOD;
        }
    }
}

ll pang(ll a, ll b) {
    if(b==0) {return 1ll;}
    ll tmp = pang(a, b >> 1);
    return ((b&1ll) ? a % MOD : 1ll) * (tmp*tmp%MOD) % MOD;
}

ll inv(ll x) {
    return pang(x, MOD-2);
}

ll C(ll a, ll b) {
    if(a < b) {swap(a, b);}
    return fac[a]*inv(fac[a-b]*fac[b]%MOD)%MOD;
}

struct Node {
    unique_ptr<Node> l, r;
    ll val = -1, sz = 0, dp = 0;

    Node() {
        l = nullptr;
        r = nullptr;
        val = -1;
        sz = 0;
        dp = 0;
    }
};

void insert(ll num, Node* nd) {
    if(nd->val == -1) {
        nd->val = num;
        return ;
    }
    if(num < nd->val) {
        if(nd->l.get() == nullptr) {
            nd->l = make_unique<Node>();
        }
        insert(num, nd->l.get());
    } else {
        if(nd->r.get() == nullptr) {
            nd->r = make_unique<Node>();
        }
        insert(num, nd->r.get());
    }
}

void traverse(Node *nd) {
    ll dpL, dpR, szL, szR;
    if(nd->l.get() == nullptr) {
        dpL = 1;
        szL = 0;
    } else {
        traverse(nd->l.get());
        dpL = nd->l.get()->dp;
        szL = nd->l.get()->sz;
    }

    if(nd->r.get() == nullptr) {
        dpR = 1;
        szR = 0;
    } else {
        traverse(nd->r.get());
        dpR = nd->r.get()->dp;
        szR = nd->r.get()->sz;
    }

    nd->sz = szL + szR + 1ll;
    nd->dp = (dpL*dpR % MOD)*C(szL+szR, szL) % MOD;
}

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        precomp();
        Node root;
        for(int now : nums) {
            insert(now, &root);
        }
        traverse(&root);
        return (root.dp+(-1+MOD)) % MOD;
    }
};