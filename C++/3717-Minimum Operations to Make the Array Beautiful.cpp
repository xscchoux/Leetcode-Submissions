// bottom-up DP, O(N*100*100)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(100, INT_MAX/2));

        dp[0][nums[0]] = 0;

        for (int i=1; i<N; i++) {
            for (int preVal = nums[i-1]; preVal < 100; preVal++) {
                for (int currVal = max(nums[i], preVal); currVal<100; currVal++) {
                    if (currVal%preVal == 0) {
                        dp[i][currVal] = min(dp[i][currVal], dp[i-1][preVal] + (currVal-nums[i]));
                    }
                }
            }
        }

        return *min_element(begin(dp[N-1]), end(dp[N-1]));
    }
};

// Top down, O(N*100*100), a little faster
class Solution {
public:
    map<pair<int, int>, int> memo;  // {index, previous value}: increments 
    int dfs(int idx, int preVal, vector<int>& nums) {
        if (idx == nums.size()) {
            return 0;
        }

        if (memo.contains({idx, preVal})) {
            return memo[{idx, preVal}];
        }

        int increments = INT_MAX/2;
        for (int curr=max(nums[idx], preVal); curr<=100; curr++) {
            if (curr%preVal == 0) {
                increments = min(increments, (curr-nums[idx]) + dfs(idx+1, curr, nums));
            }
        }

        return memo[{idx, preVal}] = increments;
    }
    
    int minOperations(vector<int>& nums) {
        // memo[{0, nums[0]}] = 0; <- no need to use this
        return dfs(1, nums[0], nums);
    }
};



// Top down, O(N*100*100), a little faster
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(100, INT_MAX/2));

        dp[0][nums[0]] = 0;

        for (int i=1; i<N; i++) {
            for (int preVal = nums[i-1]; preVal < 100; preVal++) {
                for (int currVal = ((nums[i]+preVal-1)/preVal)*preVal; currVal<100; currVal+=preVal) {
                    if (currVal%preVal == 0) {
                        dp[i][currVal] = min(dp[i][currVal], dp[i-1][preVal] + (currVal-nums[i]));
                    }
                }
            }
        }

        return *min_element(begin(dp[N-1]), end(dp[N-1]));
    }
};


// Much better
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(100, INT_MAX/2));

        dp[0][nums[0]] = 0;

        for (int i=1; i<N; i++) {
            for (int preVal = nums[i-1]; preVal < 100; preVal++) {
                for (int currVal = ((nums[i]+preVal-1)/preVal)*preVal; currVal<100; currVal+=preVal) {
                    dp[i][currVal] = min(dp[i][currVal], dp[i-1][preVal] + (currVal-nums[i]));
                }
            }
        }

        return *min_element(begin(dp[N-1]), end(dp[N-1]));
    }
};
