// O(n^3) very slow
class Solution {
public:
    int n, x, kMod = 1e9+7;
    int dfs(int num, int remain, int maxNum, vector<vector<int>>& dp) {
        if (remain == 0) {
            return 1;
        }
        if (num > maxNum) {
            return 0;
        }
        
        if (dp[num][remain] != -1) return dp[num][remain];

        int tot = 0;
        for (int curr=num; curr<=maxNum; curr++) {
            int currPow = pow(curr, x);
            if (remain < currPow) break;
            tot = (tot + dfs(curr+1, remain-currPow, maxNum, dp))%kMod;
        }

        return dp[num][remain] = tot;
    }
    int numberOfWays(int n, int x) {
        this->n = n;
        this->x = x;
        int maxNum = 1;
        
        for (int i=1; i<=n; i++) {
            if (pow(i, x) > n) {
                break;
            }
            maxNum = i;
        }

        vector<vector<int>> dp(maxNum+1, vector<int>(n+1, -1));  // dp[i][j] = count, i:starting number, j:remaining n
        
        int res = dfs(1, n, maxNum, dp);

        return res;
    }
};



// O(n*(the x-th root of n)), knapsack
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int kMod = 1e9+7;

        for (int num=1; num <= n; num++) {
            long long currPow = pow(num, x);
            for (int end=n; end>=1; end--) {
                if (end - currPow < 0) break;
                dp[end] = (dp[end] + dp[end-currPow])%kMod;
            }
        }
        
        return dp[n];
    }
};