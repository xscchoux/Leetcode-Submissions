class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        
        long long base = 1000, res = 0;
        while (n >= base) {
            res += (n-base+1);
            base = base*1000;
        }

        return res;
    }
};