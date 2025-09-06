class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int op = 1;

        if (num1 - num2 - 1 < 0) return -1;
        long long curr = num1;

        // case1: curr monotonically decreases or doesn't change -> trivial
        // case2: curr monotonically increases -> note that op grows linearly and __builtin_popcountll(curr) is O(log2(k)), so op will finally be greater than __builtin_popcountll(curr)
        while (true) {
            curr -= num2;
            if (curr < op) break;
            if (op >= __builtin_popcountll(curr)) {
                return op;
            }
            op++;
        }
        
        
        return -1;
    }
};