class Solution {
public:
    int distanceSum(int m, int n, int k) {
        long long MOD = 1e9+7;

        // Power function to calculate (x^y) % MOD
        auto power = [&](long long x, int y) -> long long {
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
        
        // combination of other elements when a pair is fixed
        long long combinations = nCr(m*n-2, k-2);
        long long res= 0;

        // sum of all vertical distances
        // n*n : pairs of grids in two rows, d: vertical distance, m-d: count of pairs of row with vertical distance d
        for (int d=1; d<m; d++) {
            res = (res + (long long)n*n*d*(m-d)%MOD) % MOD;
        }

        // sum of all horizontal distances
        // m*m : pairs of grids in two cols, d: horizontal distance, m-d: count of pairs of row with horizontal distance d
        for (int d=1; d<n; d++) {
            res = (res + (long long)m*m*d*(n-d)%MOD) % MOD;
        }

        return res*combinations % MOD;
    }
};