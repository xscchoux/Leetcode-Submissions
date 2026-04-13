const int MAX_N = 100003;   // smallest prime >= 1e5 is 100003
vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;
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
            primes.push_back(i);
        }
    }

    return 0;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i%2 == 0) {
                if (!is_prime[nums[i]]) {
                    auto it = lower_bound(begin(primes), end(primes), nums[i]);
                    int val = INT_MAX;
                    val = min(val, abs(nums[i] - *it));
                    res += val;
                }
            } else {
                if (is_prime[nums[i]]) {
                    if (nums[i] == 2) res+=2;
                    else res++;
                }
            }
        }
        return res;
    }
};