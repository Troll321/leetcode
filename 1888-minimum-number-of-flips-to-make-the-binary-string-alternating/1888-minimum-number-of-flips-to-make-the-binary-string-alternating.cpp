typedef long long ll;
const ll MAX = 1e9;

class Solution {
public:
    int minFlips(string s) {
        ll n = s.size();
        s = s+s;

        ll ans = MAX;

        ll sama[2] = {0,0}, beda[2] = {0,0};
        // 010101 dan 101010

        // Precomp
        for(int i = 0; i < n; i++) {
            sama[0] += (i+1+(s[i]-'0'))%2;
            sama[1] += (i+(s[i]-'0'))%2;
            beda[0] += (i+(s[i]-'0'))%2;
            beda[1] += (i+1+(s[i]-'0'))%2;
        }

        ans = min(ans, min(beda[0], beda[1]));

        for (int i = 1; i < n; i++) {
            ll oldI = i-1;
            ll newI = i+n-1;

            // Kurangi dulu
            if(s[oldI] == '0') {
                sama[0]--;
                beda[1]--;
            } else {
                sama[1]--;
                beda[0]--;
            }

            swap(beda[0], sama[0]);
            swap(beda[1], sama[1]);

            // Tambah yang baru
            if(s[newI] == '0') {
                if(n%2 == 0) {
                    // Beda sama awalnya
                    beda[0]++;
                    sama[1]++;
                } else {
                    beda[1]++;
                    sama[0]++;
                }
            } else {
                if(n%2 == 0) {
                    //  Beda sama awalnya
                    sama[0]++;
                    beda[1]++;
                } else {
                    sama[1]++;
                    beda[0]++;
                }
            }

            ans = min(ans, min(beda[0], beda[1]));
        }

        return ans;
    }
};