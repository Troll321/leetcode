class Solution {
public:
    string removeOuterParentheses(string s) {
        string out = "";
        int cnt = 0;
        for(char c : s) {
            if(c == '(') {
                if(cnt > 0) {out.push_back(c);}
                cnt++;
            } else {
                cnt--;
                if(cnt > 0) {out.push_back(c);}
            }
        }
        return out;
    }
};