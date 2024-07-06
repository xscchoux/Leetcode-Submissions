class Solution {
public:
    int passThePillow(int n, int time) {
        time = time%(2*(n-1));

        if (time > n-1) {
            return 1 + 2*(n-1) - time;
        } else {
            return 1 + time;
        }
    }
};