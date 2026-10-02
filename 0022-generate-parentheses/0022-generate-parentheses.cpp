
using namespace std;
vector<char> st;
bool valid(string& s) {
    st.clear();
    for(char c : s) {
        if(c == '(') {st.push_back(c);}
        else if (st.empty()) {return false;}
        else {st.pop_back();}
    }
    return st.empty();
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> out;
        out.clear();
        for(int j=0;j<2;j++) {
            for(int i=0;i<n;i++) {
                s.push_back(j == 0 ? '(' : ')');
            }
        }

        do {
            if(valid(s)) {out.push_back(s);}
        } while(next_permutation(s.begin(), s.end()));
        return out;
    }
};