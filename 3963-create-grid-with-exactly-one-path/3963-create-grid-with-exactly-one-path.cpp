class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        ans.clear();
        for(int i = 0; i < m; i++) {
            string now = ""; 
            for(int j = 0; j < n; j++) {
                now += (i == 0 || j == n-1) ? '.' : '#';
            }
            ans.push_back(now);
        } 
        return ans;
    }
};