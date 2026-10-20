const int MAXN = 1e5 + 5;
int n;
vector<int> ori, sorted, idx[MAXN];

bool cekRange(int num, int l, int r) {
    auto it = lower_bound(idx[num].begin(), idx[num].end(), l);
    if(it == idx[num].end()) {return false;}
    if(*it > r) {return false;}
    return true;
}

bool cek(int k) {
    for (int w = 0; w*k < n; w++) {
        int len = 0, bef = -1;
        for(int i = 0; i < 2*k; i++) {
            int now = ori[w*k+(i%k)];
            if(i < n && !cekRange(now, w*k, (w+1)*k-1)) {
                return false;
            }
            if(i == 0) {
                len++;
            }
            else if(now >= bef) {len++;}
            else {len = 1;}
            
            bef = now;
            if(len == k) {break ;}
        }
        if(len != k) {return false;}
    }

    return true;
}

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        for(int i = 0; i < MAXN; i++) {
            idx[i].clear();
        }
        n = nums.size();
        sorted = nums;
        ori = nums;

        // Precomp
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < n; i++) {
            idx[sorted[i]].push_back(i);
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(n%i == 0 && cek(i)) {
                ans += i;
            }
        }
        return ans;     
    }
};