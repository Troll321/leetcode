const int MAXN = 100 + 5;

bool arr[MAXN];

int cnt(int a, int b, vector<int>&nums) {
    memset(arr, 0, sizeof(arr));
    int out = 0;
    for(int i = a; i <= b; i++) {
        if(!arr[nums[i]]) {
            out++;
            arr[nums[i]] = true;
        }
    }
    return out*out;
}

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int out = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                out += cnt(i, j, nums);
            }
        }
        return out;
    }
};