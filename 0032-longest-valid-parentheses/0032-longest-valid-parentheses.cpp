#define fi first
#define se second
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<pair<bool, int>> vecn;
        vecn.clear();
        vecn.push_back({0, -1});

        for(int i = 0; i<s.size(); i++) {
            char c = s[i];
            if(c == '(') {
                vecn.push_back({1, i});
            } else {
                if(vecn.back().fi == 1) {
                    vecn.pop_back();
                    ans = max(ans, i-vecn.back().se);
                } else {
                    vecn.back().se = i;
                }
            }
        }
        return ans;
    }
};