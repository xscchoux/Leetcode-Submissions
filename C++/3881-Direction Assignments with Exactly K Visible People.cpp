const int kMod = 1e9+7;
using LL = long long;
class Solution {
public:
    LL powWithMod(LL a, LL b) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int countVisiblePeople(int n, int pos, int k) {

        // C(n-1, k)
        long long num = 1, den = 1;
        for (int kk=1; kk<=k; kk++) {
            num = (num*(n-kk))%kMod;
            den = (den*kk)%kMod;
        }

        return ((num*powWithMod(den, kMod-2))%kMod)*2%kMod;
    }
};