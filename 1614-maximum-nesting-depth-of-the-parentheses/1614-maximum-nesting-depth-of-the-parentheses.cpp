class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, nowlen = 0;
        for(auto c : s) {
            if(c == '(') {
                ans = max(ans, ++nowlen);
            } else if (c == ')') {
                nowlen--;
            }
        }
        return ans;
    }
};