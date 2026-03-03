typedef long long ll ;

string um[30];

string inv(string inp) {
    string out = "";
    for (char c : inp) {
        if(c == '1') {out += '0';}
        else {out += '1';}
    }
    reverse(out.begin(), out.end());
    return out;
}

string solve(ll n) {
    if (n == 1) {
        return "0";
    }

    if(um[n] != "") {return um[n];}
    string tmp = solve(n-1);
    um[n] = tmp + "1" + inv(tmp);
    return um[n];
}

class Solution {
public:
    char findKthBit(int n, int k) {
        string out = solve(n);
        return out[k-1];
    }
};