class Solution {
public:
    bool checkValidString(string s) {
        int star = 0, used = 0, par = 0;
        for(auto c : s) {
            if(c == '*') {
                star++;
            } else if (c == '(') {
                par++;
            } else {
                if(par == 0) {
                    if(star-used == 0) {return false;}
                    used++;
                } else {
                    par--;
                }
            }
        }

        if(star < used + par){return false;}
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*' && used) {
                s[i] = '(';
                used--;
            }
        }

        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '*' && par) {
                s[i] = ')';
                par--;
            }
        }
        par = 0;
        for(auto c : s) {
            if (c == '(') {
                par++;
            } else if (c == ')') {
                if(par == 0) {return false;}
                par--;
            }
        }
        return (par == 0);
    }
};