class Solution {
public:
    bool hasAlternatingBits(int n) {
        // The bit next to 1 is 0, and the bit two positions away is 1
        return (n&(n>>1)) == 0 && (n&(n>>2)) == (n>>2);
    }
};