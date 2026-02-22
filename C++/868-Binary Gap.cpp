class Solution {
public:
    int binaryGap(int n) {
        int res = 0, prevPos = -1, idx = 0;

        while (n > 0) {
            if (n%2 == 1) {
                if (prevPos != -1) {
                    res = max(res, idx-prevPos);
                }
                prevPos = idx;
            }
            n = n/2;
            idx++;
        }

        return res;
    }
};