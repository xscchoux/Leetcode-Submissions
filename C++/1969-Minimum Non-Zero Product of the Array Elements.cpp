using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
    LL mul(LL val, LL N) {
        if (N == 0) return 1;
        else if (N == 1) return val%kMod;
        else {
            LL temp = mul(val, N/2);
            if (N%2) {
                return (((temp*temp)%kMod)*(val%kMod))%kMod;
            } else {
                return (temp*temp)%kMod;
            }
        }
        return 1;
    }
    int minNonZeroProduct(int p) {
        LL power = 1LL<<p;
        LL N = (power-2)/2;
        LL res = mul(power-2, N);

        return ((res%kMod)*((power-1)%kMod))%kMod;
    }
};