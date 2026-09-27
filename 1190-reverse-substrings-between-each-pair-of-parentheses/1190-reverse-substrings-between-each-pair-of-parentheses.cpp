#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll idx = 0;
string reccur(string& inp, bool isRoot=false) {
    string nowS = "";
    while(idx < inp.size()) {
        char now = inp[idx];
        if(now == '(') {
            idx++;
            nowS += reccur(inp);
        } else if (now == ')') {
            if(!isRoot) {
                reverse(nowS.begin(), nowS.end());
            }
            idx++;
            return nowS;
        } else {
            nowS += now;
            idx++;
        }
    }

    if(!isRoot) {
        reverse(nowS.begin(), nowS.end());
    }
    return nowS;
}

class Solution {
public:
    string reverseParentheses(string &s) {
        idx = 0;
        return reccur(s, true);
    }
};