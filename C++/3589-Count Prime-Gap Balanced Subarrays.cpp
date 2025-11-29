// Use three pointers
// https://mocowcow.github.io/leetcode-3589-count-prime-gap-balanced-subarrays/
const int MAX_N = 50000;
vector<bool> is_prime(MAX_N + 1, true);

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

    return 0;
}();


class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        // three pointers
        int left = 0, left2 = 0; // left: left bound of window, nums[left2:i+1] contains at most one prime
        const int N = nums.size();
        int res = 0, cnt = 0; // cnt: number of primes in nums[left2:i+1]
        multiset<int> ms;

        // window1: from left to i
        // window2: from left2 to i, containing at most one prime
        // for each i, add (window1 - window2)

        for (int i=0; i<N; i++) {
            if (is_prime[nums[i]]) {
                cnt++;
                ms.insert(nums[i]);

                while (*ms.rbegin() - *ms.begin() > k) {
                    if (is_prime[nums[left]]) {
                        ms.erase(ms.find(nums[left]));
                    }
                    left++;
                }

                while (cnt > 1) {
                    if (is_prime[nums[left2]]) {
                        cnt--;
                    }
                    left2++;
                }
            }
            res += (i-left+1) - (i-left2+1);
        }

        return res;
    }
};