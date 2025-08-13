class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        int mxNum = (1LL<<31)-1;
        int max = (int)(log(mxNum)/log(3));

        return (int)pow(3, 19)%n == 0;
    }
};