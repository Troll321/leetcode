class Solution {
public:
    int minOperations(string s) {
        if(s.size() == 1) {return 0;}
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        if(sorted == s) {return 0;}
        if(sorted[0] == s[0] || sorted[s.size()-1] == s[s.size()-1]) {
            return 1;
        }
        if(s.size() == 2) {return -1;}
        if(sorted[0] == s[s.size()-1] && sorted[s.size()-1] == s[0]) {
            int cnta = 0, cntb = 0;
            for(char c : s) {
                if(c == sorted[0]) {cnta++;}
                if(c == sorted[s.size()-1]) {cntb++;}
            }
            if(cnta == 1 && cntb == 1) {return 3;}
            return 2;
        }
        return 2;
    }
};