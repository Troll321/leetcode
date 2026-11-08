const int MAXN = 250 + 5;
int row[MAXN], col[MAXN];
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            row[i]=0;
        }
        for(int j=0;j<grid[0].size();j++){
            col[j]=0;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }

        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans += grid[i][j]*((row[i]>1||col[j]>1) ? 1 : 0);
            }
        }
        return ans;
    }
};