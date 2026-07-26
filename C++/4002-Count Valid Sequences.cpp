class Solution {
public:
    int countValidSequences(int n, int k) {
        // Power function to calculate (x^y) % MOD
        auto power = [](long long x, int y) -> long long {
            long long result = 1;
            x = x % MOD;
            while (y > 0) {
                if (y & 1)
                    result = (result * x) % MOD;
                x = (x * x) % MOD;
                y = y >> 1;
            }
            return result;
        };

        // Function to calculate modular inverse of a number
        auto mod_inverse = [&](int a) -> long long {
            return power(a, MOD - 2);
        };

        // Function to calculate nCr % MOD
        auto nCr = [&](int n, int r) -> long long {
            if (r > n) return 0;
            if (r == 0) return 1;

            long long num = 1, den = 1;
            for (int i = 0; i < r; ++i) {
                num = (num * (n - i)) % MOD;
                den = (den * (i + 1)) % MOD;
            }
            return (num * mod_inverse(den)) % MOD;
        };


        // count of all different sequences: H(k, n-k) -> C(n-1, n-k) -> C(n-1, k-1)
        int allseq = nCr(n-1, k-1);

        // minus the count of all different sequences that the product of all integers is odd
        // H(k, (n-k)/2) -> C((n-k)/2-1, (n-k)/2) -> C((n+k)/2-1, k-1)
        if ((n - k)%2 != 1) {
            allseq = (allseq - nCr((n+k)/2-1, k-1) + MOD)%MOD;
        }

        return allseq;
    }
};