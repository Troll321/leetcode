#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> out;
        out.clear();
        ll nowL = 0, nowR = 0;
        for(int i = 0; i < seq.size(); i++) {
            char now = seq[i];
            if(now == '(') {
                out.push_back(nowL);
                nowL ^= 1;
            } else {
                out.push_back(nowR);
                nowR ^= 1;
            }
        }
        return out;
    }
};