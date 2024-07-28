class Solution {
public:
    vector<int> getPrime(int upper) {
        vector<int> res;
        vector<bool> isPrime(upper+1, false);
        for (int i=2; i<=upper; i++) {
            if (isPrime[i]) continue;
            int tmp = i+i;
            while (tmp <= upper) {
                isPrime[tmp] = true;
                tmp += i;
            }
        }
        for (int i=2; i<=upper; i++) {
            if (!isPrime[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
    int nonSpecialCount(int l, int r) {
        // the problem ask about the number of primes where prime**2 is within [l, r]
        int upper = sqrt(r);
        vector<int> primes = getPrime(upper);

        int special = 0;

        for (int p:primes) {
            int tmp = p*p;
            if (tmp >= l && tmp <= r) {
                special++;
            }
        }

        return r-l+1-(special);
    }
};