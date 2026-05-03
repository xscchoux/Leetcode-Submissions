// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/solutions/7333696/recursion-iterationbeats-100-by-anwenden-qflm/?envType=daily-question&envId=2025-11-08
// numOp(2^k) = 2*numOp(2^(k-1)) + 1   ( Ex: numOp(1000) = numOp(100)   + 1 +   numOp(100))
//                                                         (add 100) (change msb) (100->0) 
//            = 2^(k+1) - 1

// Ex:
// k=0: numOp(1) = 2*numOp(0) + 1 = 1 = 2^1 - 1
// k=1: numOp(2) = 2*numOp(1) + 1 = 3 = 2^2 - 1
// k=2: numOp(4) = 2*numOp(3) + 1 = 7 = 2^3 - 1

class Solution {
public:
    int f(int num) {
        if (num == 0) return 0;
        int msb = log2(num);
        int stepToRemoveMSB = pow(2, msb+1) - 1;
        return stepToRemoveMSB - f(num^(1<<msb));
    }
    int minimumOneBitOperations(int n) {
        return f(n);
    }
};