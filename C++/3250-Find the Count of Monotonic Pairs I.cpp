class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int N = nums.size(), kMod = 1e9+7, res = 0;
        vector<vector<int>> dp(N+1, vector<int>(51, 0)); // dp[i][num] : number of qualified arr1[0:i+1] that ends with num
        dp[0][0] = 1;


        for (int i=0; i<N; i++) {
            int idx = i+1;
            for (int num=0; num<=nums[i]; num++) {
                for (int prevNum=0; prevNum<=num; prevNum++) {
                    if (dp[idx-1][prevNum] > 0) {
                        if (i == 0 || nums[i-1] >= nums[i] - num + prevNum )  {
                            dp[idx][num] = (dp[idx][num] + dp[idx-1][prevNum])%kMod;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        for (int num=0; num<=50; num++) {
            res = (res + dp[N][num])%kMod;
        }

        return res;
    }
};