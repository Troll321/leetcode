class Solution {
public:
    int minChanges(string s) {
        int ans = 0, sm = 0, bef = 0;
        for(int i=0; i < s.size(); i++) {
            int now = s[i]-'0';
            if(i == 0) {
                bef = now;
                sm = 1;
                continue ;
            }
            if(bef != now) {
                if(sm % 2 == 0) {
                    bef = now;
                    sm = 1;
                } else {
                    ans++;
                    s[i] = bef+'0';
                    sm++;
                }
            } else {
                sm++;
            }
        }
        return ans;
    }
};