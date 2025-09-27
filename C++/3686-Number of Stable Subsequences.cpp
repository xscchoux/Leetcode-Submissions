// First AC
class Solution {
public:
    int kMod = 1e9+7;
    int countStableSubsequences(vector<int>& nums) {
        int N = nums.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(3, 0))); // dp[index][parity][consecutive count] = number of subsequences so far

        dp[0][nums[0]%2][1] = 1;
        int res = 0;

        for (int i=1; i<N; i++) {
            int currParity = nums[i]%2;
            
            // add previous sequences
            for (int p=0; p<=1; p++) {
                for (int count=1; count<3; count++) {
                    dp[i][p][count] = dp[i-1][p][count];
                }
            }

            // start a new sequence
            dp[i][currParity][1] += 1;

            // connect to old sequences
            for (int p=0; p<=1; p++) {
                for (int count=1; count<3; count++) {
                    if (p == currParity) {
                        if (count == 2) continue;
                        dp[i][p][count+1] = (dp[i][p][count+1] + dp[i-1][p][count])%kMod;
                    } else {
                        dp[i][currParity][1] = (dp[i][currParity][1] + dp[i-1][p][count])%kMod;
                    }
                }
            }
        }

        for (int p=0; p<=1; p++) {
            for (int count=1; count<3; count++) {
                res = (res + dp[N-1][p][count])%kMod;
            }
        }
        
        return res;
    }
};



// Clever, concise and fast
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        long long one[2] = {}, two[2] = {};
        int kMod = 1e9+7;

        for (int num:nums) {
            int parity = num%2;
            
            // extend
            two[parity] = (two[parity] + one[parity])%kMod;
            one[parity] = (one[parity] + 1 + one[1-parity] + two[1-parity])%kMod;
        }

        return (one[0] + one[1] + two[0] + two[1])%kMod;
    }
};