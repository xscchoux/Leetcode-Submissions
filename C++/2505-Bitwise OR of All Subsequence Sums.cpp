class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        // 10^9 = 2^x, x = 29.897352854
        long long res = 0;
        int carry = 0, bit = 0;

        for (int i=0; i<=30; i++) {
            for (int &num:nums) bit += num&1, num >>= 1;
            if (bit > 0) res += (1LL<<i);
            bit /= 2;
        }

        int j = 31;
        while (bit > 0) {
            res += (1LL<<j); 
            bit = bit/2;
            j++;
        }

        return res;
    }
};