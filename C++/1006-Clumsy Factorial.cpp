class Solution {
public:
    int clumsy(int n) {
        int res = 0;
        bool first = true;
        for (int num = n; num>=1; num-=4) {
            int m = (first?1:-1);
            if (num >= 4) {
                res += m*(num*(num-1)/(num-2)) + num-3;
            } else if (num == 3) {
                res += m*num*(num-1)/(num-2);
            } else if (num == 2) {
                res += m*num*(num-1);
            } else {
                res += m*num;
            }
            first = false;
        }

        return res;
    }
};