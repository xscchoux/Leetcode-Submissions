using LL = long long;
class Solution {
public:
    LL powWithMod(LL a, int b, int kMod) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int superPow(int a, vector<int>& b) {
        LL res = 1;
        for (int digit:b) {
            res = (powWithMod(res, 10, 1337)*powWithMod(a, digit, 1337))%1337;  // a^(10*b) == (a^b)^10
        }
        return res;
    }
};