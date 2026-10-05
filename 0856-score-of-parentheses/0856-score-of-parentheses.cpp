#define fi first
#define se second

class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<pair<int, bool>> vec;
        vec.clear();
        vec.push_back({0, false});
        for(char c:s) {
            if(c == '(') {
                vec.push_back({1, false});
            } else {
                pair<int, bool> tmp = vec.back();
                tmp.fi -= tmp.se;
                vec.pop_back();
                if(vec.size() == 1) {
                    vec.back().fi += tmp.fi;
                } else {
                    vec.back().fi += 2*tmp.fi;
                    vec.back().se = true;
                }
            }
        }
        return vec.back().fi;
    }
};