// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/6199469/python-combinatorics-explained/
// create an array of n-k elements without same adjacent values, and add remaining k elements: H(n-k, k) 
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        // Power function to calculate (x^y) % MOD
        const int kMod = 1e9+7;
        auto power = [](long long x, int y) -> long long {
            long long result = 1;
            x = x % kMod;
            while (y > 0) {
                if (y & 1)
                    result = (result * x) % kMod;
                x = (x * x) % kMod;
                y = y >> 1;
            }
            return result;
        };

        // Function to calculate modular inverse of a number
        auto mod_inverse = [&](int a) -> long long {
            return power(a, kMod - 2);
        };

        // Function to calculate nCr % MOD
        auto nCr = [&](int n, int r) -> long long {
            if (r > n) return 0;
            if (r == 0) return 1;

            long long num = 1, den = 1;
            for (int i = 0; i < r; ++i) {
                num = (num * (n - i)) % kMod;
                den = (den * (i + 1)) % kMod;
            }
            return (num * mod_inverse(den)) % kMod;
        };

        return m*power(m-1, n-k-1)%kMod*nCr(n-1, k)%kMod;  // m * (m-1)^(n-k-1) * H(n-1, k)
    }
};