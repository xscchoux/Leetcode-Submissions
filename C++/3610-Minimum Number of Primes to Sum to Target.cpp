class Solution {
public:
    bool isPrime(int num) {

        for (int factor = 2; factor*factor <= num; factor++) {
            if (num%factor == 0) return false;
        }

        return true;
    }
    int minNumberOfPrimes(int n, int m) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        int cnt = 0;
        for (int num=2; num <= n; num++) {
            if (isPrime(num)) {
                cnt++;
                for (int j = num; j <= n; j++) {
                    if (dp[j-num] != INT_MAX) dp[j] = min(dp[j], dp[j-num]+1);
                }
            }
            if (cnt == m) break;
        }

        return dp.back()==INT_MAX? -1:dp.back();
    }
};