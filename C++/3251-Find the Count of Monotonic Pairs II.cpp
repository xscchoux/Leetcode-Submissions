using LL = long long;
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int N = nums.size(), kMod = 1e9+7;
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(N+1, vector<int>(mx+1, 0));
        dp[0][0] = 1;
        LL res = 0;

        vector<vector<int>> preSum(N+1, vector<int>(mx+1, 0));
        // dp[idx][num] += (dp[idx-1][min(num, nums[i-1]-(nums[i]-num))] for num from 0 to nums[i]) if (nums[i-1]-(nums[i]-num)>=0
        // preSum[idx][num] = (num>0?preSum[idx][num-1]:0) + dp[idx][num]

        for (int i=0; i<N; i++) {
            int idx = i+1;       
            for (int num=0; num<=nums[i]; num++) {
                if (i == 0) {
                    dp[idx][num]++;
                    preSum[idx][num] = ((num>0?preSum[idx][num-1]:0) + dp[idx][num])%kMod;
                } else if ( (nums[i-1] - (nums[i] - num)) >= 0) {
                    dp[idx][num] = (dp[idx][num] + preSum[idx-1][min(num, nums[i-1] - (nums[i] - num))])%kMod;
                    preSum[idx][num] = ((num>0?preSum[idx][num-1]:0) + dp[idx][num])%kMod;
                }
            }
        }

        for (int num=0; num<=mx; num++) {
            res = (res + dp[N][num])%kMod;
        }

        return res;        
    }
};



// https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/solutions/5630696/linear-time-combinations-difference-sequence/
// combinatorics, extremely hard
class Solution {
public:
    int modInverse(long long num, int kMod) {
        int expr = kMod-2, res = 1;
        while (expr > 0) {
            if (expr%2) {
                res = (res*num)%kMod;
            }
            num = (num*num)%kMod;
            expr /= 2;
        }
        return res;
    }
    int countOfPairs(vector<int>& nums) {
        int N = nums.size(), kMod = 1e9+7;
        int minHeight = 0;
        for (int i=0; i<N; i++) {
            if (i>0 && nums[i]-nums[i-1] > 0) {
                minHeight += nums[i] - nums[i-1];
            }
            if (minHeight > nums[i]) return 0;
        }

        int diff = nums.back() - minHeight;

        // H(diff+1, N) = C(diff+N, N)
        long long nominator = 1, denominator = 1;
        for (int i=0; i<N; i++) {
            nominator = (nominator*(diff+N-i))%kMod;
            denominator = (denominator*(i+1))%kMod;
        }

        return (nominator*modInverse(denominator, kMod))%kMod;
    }
};