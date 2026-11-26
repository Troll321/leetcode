class Solution {
public:
    bool canAliceWin(int n) {
        bool win = false;
        int now = 10;
        while(n > 0) {
            if(n < now) {break ;}
            n -= now;
            now--;
            win ^= 1;
        }
        return win;
    }
};