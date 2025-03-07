vector<int> primes;
bool getPrime = false;
int N = 1e6;

// generated using ChatGPT
void sieve() {
    std::vector<bool> isPrime(N + 1, true);  // Assume all numbers are prime
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {  // Found a prime
            for (int j = i * i; j <= N; j += i) {  // Mark multiples of i
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}


class Solution {
public:
    Solution() {
        if (!getPrime) {
            sieve();
            getPrime = true;
        }
    }
    vector<int> closestPrimes(int left, int right) {
        int idx = lower_bound(begin(primes), end(primes), left) - begin(primes);
        int dist = INT_MAX;
        vector<int> res = {-1, -1};
        while (idx+1 < primes.size() && primes[idx+1] <= right) {
            if (primes[idx+1] - primes[idx] < dist) {
                dist = min(dist, primes[idx+1]-primes[idx]);
                res = {primes[idx], primes[idx+1]};
                if (dist == 2 || dist == 1) break;   // smart pruning
            }
            idx++;
        }

        return res;
    }
};