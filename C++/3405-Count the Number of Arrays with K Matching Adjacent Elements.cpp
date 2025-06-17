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


// Another approach:
// We can first choose the initial number in m ways. Then, from the remaining n-1 positions, we select n-k-1 positions to fill. 
// Each of these selected positions can be filled in m - 1 ways (since they must differ from the previous one).
// Thus, the answer is
// m × C(n - 1, n - k - 1) × (m - 1)^(n - k - 1),
// which matches the result derived earlier.

using LL = long long;
const int kMod = 1e9+7, MAX_N = 1e5;

LL fac[MAX_N+1], inv_fac[MAX_N+1];

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
    void fillVector() {
        if (fac[0]) return;
        // fill fac and inv_fac
        fac[0] = 1;
        for (int i=1; i<=MAX_N; i++) {
            fac[i] = (fac[i-1]*i)%kMod;
        }

        inv_fac[MAX_N] = powWithMod(fac[MAX_N], kMod-2, kMod);
        
        for (int i=MAX_N-1; i>=0; i--) {
            inv_fac[i] = (inv_fac[i+1]*(i+1))%kMod;
        }
    };
    LL comb(int N, int M) {
        return fac[N]*inv_fac[N-M]%kMod*inv_fac[M]%kMod;
    }
    int countGoodArrays(int n, int m, int k) {
        fillVector();
        return comb(n-1, k)*m%kMod*powWithMod(m-1, n-1-k, kMod)%kMod;
    }
};