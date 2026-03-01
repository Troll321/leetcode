class Solution {
public:
    int minPartitions(string n) {
        int out = 0;
        for (int i = 0; i < n.size(); i++) {
            out = max(out, n[i]-'0');
        }
        return out;
    }
};