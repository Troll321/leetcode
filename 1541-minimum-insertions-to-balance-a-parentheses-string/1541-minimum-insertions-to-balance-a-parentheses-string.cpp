class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int cnt = 0, used = 0;
        bool simpen = false;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if(c == '(') {
                if(simpen) {
                    ans++;
                    i -= 2;
                    continue ;
                }
                cnt++;
            } else {
                if(simpen) {
                    simpen = false;
                    if(cnt == 0) {used++;}
                    else {cnt--;}
                } else {
                    simpen = true;
                }
            }
            
            if(simpen && i+1 == s.size()) {ans++; i--;}
        }

        ans += 2*cnt + used;
        return ans;
    }
};