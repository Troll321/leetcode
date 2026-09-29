#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 100 + 5;

bool dp[MAXN][MAXN][MAXN];

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        ll w = max(n, m);
        if((n+m-1) % 2 == 1) {return false;}
        if(grid[n-1][m-1] == '(') {return false;}
        if(grid[0][0] == ')') {return false;}

        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= m; j++) {
        //         for(int k = 0; k <= w + 2; k++) {
        //             dp[i][j][k] = false;
        //         }
        //     }
        // }
        memset(dp, 0, sizeof(dp));

        for(int i = n; i >= 1; i--) {
            for(int j = m; j >= 1; j--) {
                for(int k = 0; k <= w; k++) {
                    if(i == n && j == m) {
                        if (k == 1) {
                            dp[i][j][k] = true;
                            break ;
                        }
                        continue ;
                    }
                    char now = grid[i-1][j-1];
                    if(now == '(') {
                        dp[i][j][k] = max(dp[i+1][j][k+1], dp[i][j+1][k+1]);
                    } else {
                        if(k == 0) {continue ;}
                        dp[i][j][k] = max(dp[i+1][j][k-1], dp[i][j+1][k-1]);
                    }
                }
            }
        }

        return dp[1][1][0];
    }
};