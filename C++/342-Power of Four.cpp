// This is fast, but not ideal, because 0xaaaaaaaa gets implicitly promoted to unsigned int during the bitwise operation
// 0xaa -> 10101010
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        return (n&(n-1)) == 0 && (n&0xaaaaaaaa) == 0;  // Though 0xaaaaaaaa is greater than 2^31-1, it's converted to unsigned int here.
    }
};

// Better
class Solution {
public:
    bool isPowerOfFour(int n) {
        // Note that the & operator has lower precedence than the == operator, 
        return (n > 0) && ((n&(n-1)) == 0) && (n%3==1);
    }
};