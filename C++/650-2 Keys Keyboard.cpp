// My DP solution
class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2+n/2, INT_MAX/2));  // dp[index][length of copied]:min number of operations
        if (n == 1) return 0;
        dp[1][1] = 1;

        for (int i=2; i<=n; i++) {
            for (int paste = 1; paste <= 1+n/2; paste++) {
                // paste
                if (paste + i - 1 <= n) {
                    dp[i+paste-1][paste] = min(dp[i+paste-1][paste], dp[i-1][paste]+1);
                } else {
                    break;
                }
                // copy again
                if (i <= 1+n/2) dp[i][i] = min(dp[i][paste] + 1, dp[i][i]);
            }
        }

        return *min_element(dp[n].begin(), dp[n].end());
    }
};



// DP2, much simpler
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 1000);
        dp[1] = 0;
        for (int i=2; i<=n; i++) {
            for (int j=1; j <= i/2; j++) {
                if (i%j == 0) {
                    dp[i] = dp[j] + 1 + (i-j)/j;
                }
            }
        }

        return dp[n];

    }
};


// prime factorization. If we want 'AAAAAA', (CPPPPP) requires 6 six steps but (CP)(CPP) requires only five steps. The more multiplication the better 
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int d = 2; // prime factor
        while (n != 1) {
            while (n%d == 0) {
                res += d;
                n /= d;
            }
            d++;
        }
        return res;
    }
};