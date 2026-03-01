typedef long long ll;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<ll, ll> um;
        ll idx = 0;
        for (auto num : nums) {
            if(um.find(target-num) != um.end()) {
                vector<int> output = {(int)idx, (int)um[target-num]};
                return output;
            }
            um[num] = idx;
            idx++;
        }

        return {};
    }
};