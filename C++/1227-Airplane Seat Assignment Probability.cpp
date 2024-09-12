// https://algo.itcharge.cn/Solutions/1200-1299/airplane-seat-assignment-probability/
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1?1:0.5;
    }
};