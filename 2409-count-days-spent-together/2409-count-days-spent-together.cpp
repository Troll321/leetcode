#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;

ll arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll pref[13] = {0};

ll conv(string inp) {
    ll m = (inp[0]-'0')*10 + inp[1]-'0';
    ll d = (inp[3]-'0')*10 + inp[4]-'0';
    return pref[m-1]+d;
}

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        for(int i=1;i<13;i++) {
            pref[i] = pref[i-1]+arr[i];
        }
        pll a = {conv(arriveAlice), conv(leaveAlice)};
        pll b = {conv(arriveBob), conv(leaveBob)};

        return max(0ll, min(a.se, b.se) - max(a.fi, b.fi) + 1ll);
    }
};