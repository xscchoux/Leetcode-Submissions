// https://leetcode.com/problems/find-maximum-removals-from-source-string/solutions/5903944/knapsack-dp-complete-intuiton-to-solution/
class Solution {
public:
    int Ns, Np;
    int dfs(string& source, string& pattern, int i, int j, unordered_set<int>& targetSet, vector<vector<int>>& memo) {
        if (j == Np) return 0;
        if (i == Ns) return INT_MAX/2;
        if (Ns-i < Np - j) return INT_MAX/2;    // pruning
        if (memo[i][j] != -1) return memo[i][j];

        // skip source[i]
        int operation = dfs(source, pattern, i+1, j, targetSet, memo);
        // use source[i] when source[i] == pattern[j]
        if (source[i] == pattern[j]) {
            int toAdd = (targetSet.contains(i)?1:0);
            operation = min(operation, toAdd + dfs(source, pattern, i+1, j+1, targetSet, memo));
        }

        return memo[i][j] = operation;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        Ns = source.size();
        Np = pattern.size();
        vector<vector<int>> memo(Ns, vector<int>(Np, -1));
        unordered_set<int> targetSet(begin(targetIndices), end(targetIndices));
        // calculate the minimum number of "used" index from targetIndices
        int ans = dfs(source, pattern, 0, 0, targetSet, memo);

        return targetIndices.size() - ans;
    }
};


// bottom-up, hard!
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int Ns = source.size(), Np = pattern.size();
        unordered_set<int> targetSet(begin(targetIndices), end(targetIndices));

        // dp[i][j] : maximum number of removed indexes when considering source[0~i] and pattern[0~j]
        vector<vector<int>> dp(Ns+1, vector<int>(Np+1, INT_MIN));
        dp[0][0] = 0;
        for (int i=1; i<=Ns; i++) {
            dp[i][0] = dp[i-1][0] + (targetSet.contains(i-1)?1:0);
        }


        for (int i=1; i<=Ns; i++) {
            for (int j=1; j<=Np; j++) {
                // skip or remove
                if (targetSet.contains(i-1)) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j]);  // remove
                } else {
                    dp[i][j] = dp[i-1][j];  // skip
                }
                // use source[i-1]
                if (source[i-1] == pattern[j-1]) {         
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                }
            }
        }

        return dp[Ns][Np];
    }
};