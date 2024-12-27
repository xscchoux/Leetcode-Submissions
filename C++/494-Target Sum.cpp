class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        unordered_map<int, int> curr;
        curr[nums[N-1]]++; curr[-nums[N-1]]++;

        for (int i=N-2; i>=0; i--) {
            unordered_map<int, int> newMap;
            for (auto &[k, v]:curr) {
                newMap[nums[i]+k] +=v;
                newMap[-nums[i]+k] += v;
            }
            curr = newMap;
        }

        return curr[target];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        // (target+sum)%2 should be 0
        // tot(P) - tot(N) = target
        // tot(P) + tot(N) = sum
        // tot(P) = (target+sum)/2, get all different kinds of P

        if ((sum+target)%2 != 0) return 0;
        if (abs(target) > sum) return 0;  // note the case: target < 0 and abs(target) > sum

        vector<int> dp(1+(target+sum)/2, 0);
        dp[0] = 1;
        for (int num:nums) {
            for (int i=(target+sum)/2; i>=0; i--) {
                if (num > i) break;
                dp[i] += dp[i-num];
            }
        }

        return dp[(target+sum)/2];
    }
};