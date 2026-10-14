class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string out = "";
        for(int i = 0; i < num; i++) {
            if(sum >= 9) {
                out += '9';
                sum -= 9;
            } else {
                out += '0' + sum;
                sum = 0;
            }
        }
        if(sum > 0) {return "";}
        return out;
    }
};