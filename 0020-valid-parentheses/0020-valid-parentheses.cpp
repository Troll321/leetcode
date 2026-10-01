#include <bits/stdc++.h>
using namespace std;
vector<char> vec;
class Solution {
public:
    bool isValid(string s) {
        vec.clear();
        for(auto c : s) {
            if(vec.empty()) {vec.push_back(c); continue ;}
            char bnow = vec.back();
            if((bnow == '(' && c == ')') ||
            (bnow == '{' && c == '}') ||
            (bnow == '[' && c == ']')) {
                vec.pop_back();
            } else {
                vec.push_back(c);
            }
        }
        return vec.empty();
    }
};