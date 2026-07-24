class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // n is even: s + m - 1 + m
        // n is odd:  s + m - 1 + m - 1
        if (n == 1) return s;
        
        if (n%2 == 0) {
            return s + (long long)(n/2)*m - (n-1)/2;
        } else {
            return s + (long long)((n-1)/2)*m - (n-1)/2 + 1;
        }

    }
};