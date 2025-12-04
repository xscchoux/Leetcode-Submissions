class Solution {
public:
    int countCollisions(string directions) {
        int right = 0, stationary = 0, res = 0;

        for (char c:directions) {
            if (c == 'R') {
                stationary = 0;
                right++;
            } else if (c == 'S') {
                res += right; 
                stationary = 1;
                right = 0;
            } else {
                if (right == 0 && stationary == 0) continue;
                res += right>0?(right+1):0;
                res += stationary;
                right = 0;
                stationary = 1;
            }
        }

        return res;
    }
};