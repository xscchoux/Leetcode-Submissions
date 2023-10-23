class Solution {
public:
    bool isPowerOfFour(int n) {
        // Note that the & operator has lower precedence than the == operator, 
        return (n > 0) && ((n&(n-1)) == 0) && (n%3==1);
    }
};