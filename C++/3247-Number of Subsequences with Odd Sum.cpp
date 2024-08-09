// DP
class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        // if current num is odd, even = preEven + preOdd, odd = preOdd + preEven
        // if current num is even, even = preEven + preEven, odd = preOdd + preOdd 
        int preEven = 1, preOdd = 0;
        const int kMod = 1e9+7;

        for (int num:nums) {
            int even, odd;
            if (num%2) {
                even = (preEven + preOdd)%kMod;
                odd = (preEven + preOdd)%kMod;
            } else {
                even = (preEven*2)%kMod;
                odd = (preOdd*2)%kMod;
            }
            preEven = even; preOdd = odd;
        }
        return preOdd;
    }
};


// Math only
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
    int subsequenceCount(vector<int>& nums) {
        // C(n,1)+C(n,3)+C(n,5)+⋯ = 2^(n−1)
        int kMod = 1e9+7;
        int odd = 0, even = 0;
        for (int num:nums) {
            if (num%2) odd++;
            else even++;
        }
        if (!odd) return 0;
        int res = (powWithMod(2, even, kMod)*powWithMod(2, odd-1, kMod))%kMod;

        return res;
    }
};