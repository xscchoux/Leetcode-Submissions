const int MAX_N = 500000;
vector<bool> is_prime(MAX_N + 1, true);
vector<long long> preSum = {0};

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
    
    long long currSum = 0;
    for (int i=2; i<MAX_N; i++) {
        if (is_prime[i]) {
            currSum += i;
            if (currSum > MAX_N) break;
            if (is_prime[currSum]) {
                preSum.push_back(currSum);
            }
        }
    }

    return 0;
}();


class Solution {
public:
    int largestPrime(int n) {
        
        int idx = upper_bound(begin(preSum), end(preSum), n) - begin(preSum);
        return preSum[idx-1];

    }
};