using LL = long long;
class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) return x;

    // x = 100001  (binary representation of x)
    // n = 1011    (binary representation of n)
    // Our goal is to fill the 0 bits in x with bits from n  == >  x = 1 1 0 1 1 1

        LL res = x;
        n--;

        LL k=0;
        while (n > 0) {
            if ((x & (1LL<<k)) == 0) {
                res |= (n&1)*(1LL<<k);
                n >>= 1;
            }
            k++;
        }

        return res;
    }
};
