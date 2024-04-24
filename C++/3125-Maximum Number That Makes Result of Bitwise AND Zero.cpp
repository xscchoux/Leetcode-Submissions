class Solution {
public:
    long long maxNumber(long long n) {
        int highest = floor(log2(n));
        
        long long lowBound = pow(2, highest) - 1;

        return lowBound;
        
    }
};