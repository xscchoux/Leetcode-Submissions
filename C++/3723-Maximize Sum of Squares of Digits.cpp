class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num*9) return "";

        string res = "";
        
        for (int i=0; i<num; i++) {
            if (sum >= 9) {
                res += '9';
                sum -= 9;
            } else {
                res += sum + '0';
                sum = 0;
            }
        }

        return res;
    }
};