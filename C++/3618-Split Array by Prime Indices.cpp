class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1 || ((n > 2) && (n%2 == 0)))
            return false;
        else {
            if (n == 2) {
                return true;
            } else {
                int cnt = 0;
                // Check how many numbers divide 
                // n in the range 2 to sqrt(n)
                for (int i = 3; i * i <= n; i += 2) {
                    if (n % i == 0)
                        cnt++;
                }

                // if cnt is greater than 0, 
                // then n is not prime
                if (cnt > 0) return false;
                else return true;
            }
        }
    }
    long long splitArray(vector<int>& nums) {
        long long a = 0, b = 0;
        int N = nums.size();

        for (int i=0; i<N; i++) {
            if (isPrime(i)) {
                a += nums[i];
            } else {
                b += nums[i];
            }
        }

        return abs(a - b);
    }
};