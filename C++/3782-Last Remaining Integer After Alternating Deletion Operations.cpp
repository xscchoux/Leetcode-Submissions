// Simulation, can be further simplified
class Solution {
public:
    long long lastInteger(long long n) {
        long long low = 1, cnt = n, interval = 1;
        int isLeft = 1;
        while (cnt > 1) {
            if (isLeft) {
                if (cnt%2 == 1) {
                    // low = low;
                    // high = high;
                    cnt = cnt - cnt/2;
                } else {
                    // low = low;
                    // high = high-interval;
                    cnt = cnt - cnt/2;
                }
            } else {
                if (cnt%2 == 1) {
                    // low = low;
                    // high = high;
                    cnt = cnt - cnt/2;
                } else {
                    low = low + interval;
                    // high = high;
                    cnt = cnt - cnt/2;
                }                
            }
            interval*=2;
            isLeft = 1 - isLeft;
        }
        return low;
    }
};