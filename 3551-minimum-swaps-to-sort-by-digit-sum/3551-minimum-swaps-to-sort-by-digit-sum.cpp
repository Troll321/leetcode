const int MAXN = 1e5 + 5;
int n;

int sum(int x) {
    int out = 0;
    while(x > 0) {
        out += x % 10;
        x /= 10;
    }
    return out;
}

bool cmp(int a, int b) {
    int sA = sum(a);
    int sB = sum(b);
    if(sA == sB) {return a < b;}
    return sA < sB;
}

void print(vector<int>& v) {
    for(int x:v){
        cout << x << " ";
    } cout << "!\n";
}

unordered_map<int, int> um;
vector<int> vec;
bool visited[MAXN];
int dfs(int now, int len) {
    if(visited[now]) {return len-1;}
    visited[now] = true;
    int nxt = vec[now-1];
    return dfs(nxt, len+1);
}

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        um.clear();
        vec.clear();

        vector<int> nw = nums;
        vec = nums;
        n = nums.size();
        for(int i = 0; i<=n; i++) {visited[i] = false;}
        sort(nw.begin(), nw.end(), cmp);
        for(int i = 0; i < n; i++) {
            um[nw[i]] = i+1;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            vec[i] = um[vec[i]];
        }
        for(int i = 1; i <= n; i++) {
            if(visited[i]) {continue ;}
            ans += dfs(i, 0);
        }

        return ans;
    }
};