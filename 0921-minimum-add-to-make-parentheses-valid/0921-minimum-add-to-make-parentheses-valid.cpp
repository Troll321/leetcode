class Solution {
public:
    int minAddToMakeValid(string s) {
        int used = 0, cnt = 0;
        for (char c : s) {
            if(c == '(') {cnt++;}
            else {
                if(cnt == 0) {used++;}
                else {cnt--;}
            }
        }
        return used + cnt;
    }
};