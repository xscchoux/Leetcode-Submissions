// https://leetcode.com/problems/number-of-zigzag-arrays-i/solutions/7229999/python-prefix-sum-dp/
class Solution {
public:
    int kMod = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int M = r-l+1;
        vector<vector<long long>> dp(n, vector<long long>(M, 0));
        
        for (int i=l; i<=r; i++) {
            dp[0][i-l]++;
        }
        
        // for this case: A[0] < A[1] > A[2] < A[3] > A[4] ....
        for (int i=1; i<n; i++) {
            int tot = 0;
            for (int k=0; k<M; k++) {
                tot = (tot + dp[i-1][k])%kMod;
            }

            if (i&1) {
                for (int j=M-1; j>=0; j--) {
                    tot = (tot - dp[i-1][j] + kMod)%kMod;
                    dp[i][j] = tot;
                }
            } else {
                for (int j=0; j<M; j++) {
                    tot = (tot - dp[i-1][j] + kMod)%kMod;
                    dp[i][j] = tot;
                }                
            }
        }

        int res = 0;
        for (int i=0; i<M; i++) {
            res = (res + dp[n-1][i])%kMod;
        }

        // Multiply res by two for another case: A[0] > A[1] < A[2] > A[3] < A[4] ....
        return (2*res)%kMod;
    }
};