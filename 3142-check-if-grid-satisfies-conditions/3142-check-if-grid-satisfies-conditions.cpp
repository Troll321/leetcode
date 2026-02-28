class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if(((i < grid.size()-1) && grid[i][j] != grid[i+1][j]) || (j < grid[i].size() - 1 && grid[i][j] == grid[i][j+1])) {
                    return false;
                }
            }
        }
        return true;
    }
};