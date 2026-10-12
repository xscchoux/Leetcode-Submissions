const int MAX_N = 1e6;
vector<bool> is_prime(MAX_N + 1, true);
vector<int> prime;

int fillVector = []() {
     // is_prime[i] == true means i is prime
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i=2; i<=MAX_N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }

    return 0;
}();

class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> res;
        for (int p:prime) {
            if (p <= n) {
                if (s-p >= 0) {
                    s -= p;
                    res.push_back(p);
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        return res;
    }
};