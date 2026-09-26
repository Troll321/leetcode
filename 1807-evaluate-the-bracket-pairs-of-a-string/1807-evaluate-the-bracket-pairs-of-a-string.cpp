#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        mp.clear();
        for (auto v : knowledge) {
            mp[v[0]] = v[1];
        }
        string output = "", nowKey = "";
        bool isKey = false;
        for(int i = 0; i < s.size(); i++) {
            char now = s[i];
            if(now == '(') {
                isKey = true;
            } else if (now == ')') {
                isKey = false;
                auto it = mp.find(nowKey);
                if(it == mp.end()) {
                    output += "?";
                } else {
                    output += it->second;
                }
                nowKey = "";
            } else {
                if(isKey) {
                    nowKey += now;
                } else {
                    output += now;
                }
            }
        }
        return output;
    }
};