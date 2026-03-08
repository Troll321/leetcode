typedef long long ll;
const ll MAXN = 1e5;

ll sToI(string s) {
    ll out = 0;
    ll idx = 0;
    for (int i = (int)s.size()-1; i >= 0; i--) {
        if(s[i] == '1') {
            out += 1ll << idx;
        }
        idx++;
    }
    return out;
}

string iToS(ll num, ll n) {
    string str = "";
    while(num > 0) {
        str += to_string(num%2);
        num = num >> 1;
    }
    while(str.size() < n) {
        str.push_back('0');
    }
    reverse(str.begin(), str.end());

    return str;
}

bool arr[MAXN];

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        ll mx = 1 << nums.size();
        memset(arr, 0, sizeof(bool)*mx);
        for(string s : nums) {
            arr[sToI(s)] = true;
        }
        for (int i = 0; i < mx; i++) {
            if(!arr[i]) {return iToS(i, nums.size());}
        }
        return "0";
    }
};