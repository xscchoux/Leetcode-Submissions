class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int N = nums.size();
        vector<int> dp(2*limit+1, 0);

        for (int i=0; i<N/2; i++) {
            int mn = min(nums[i], nums[N-1-i]);
            int mx = max(nums[i], nums[N-1-i]);

            dp[2] += 2;
            dp[mn+1] -= 1;
            dp[mn+mx] -= 1;
            if (mn + mx + 1 <= 2*limit) {
                dp[mn+mx+1] += 1;
            }
            if (mx + limit + 1 <= 2*limit) {
                dp[mx+limit+1] += 1;
            }            
        }
        
        int running = 0, res = INT_MAX;
        for (int num=2; num<=2*limit; num++) {
            running += dp[num];
            res = min(res, running);
        }

        return res;
    }
};