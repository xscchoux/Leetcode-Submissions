using LL = long long;
class Solution {
public:
    LL powWithMod(LL a, LL b, int kMod) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        int kMod = 1e9+7;
        LL even = (n+1)/2, odd = n-even;

        return powWithMod(5, even, kMod)*powWithMod(4, odd, kMod)%kMod;
    }
};