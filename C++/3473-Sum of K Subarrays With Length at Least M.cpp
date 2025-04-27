class Solution {
public:
    int m, N;
    int dp[2001][2001][2];
    int dfs(int idx, int kleft, int canConnect, vector<int>& nums, vector<int>& preSum) {
        if (N-idx < kleft*m) return INT_MIN/2;
        if (idx == N) {
            if (kleft > 0) return INT_MIN/2;
            return 0;
        }

        if (dp[idx][kleft][canConnect] != INT_MIN) return dp[idx][kleft][canConnect];

        int res = INT_MIN/2;
        if (N-idx >= m) {
            if (kleft > 0) res = max(res, preSum[idx+m] - preSum[idx] + dfs(idx + m, kleft-1, 1, nums, preSum) );
        }
        
        // connect to existing subarray
        if (canConnect) {
            res = max(res, nums[idx] + dfs(idx+1, kleft, canConnect, nums, preSum));
        }

        // skip current num
        res = max(res, dfs(idx+1, kleft, 0, nums, preSum));

        return dp[idx][kleft][canConnect] = res;
    }

    int maxSum(vector<int>& nums, int k, int m) {
        this->m = m;
        this->N = nums.size();
        vector<int> preSum = {0};
        fill(&dp[0][0][0], &dp[0][0][0] + 2001 * 2001 * 2, INT_MIN);
        // memset(dp, -1, sizeof(dp));
        // vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(k+1, vector<int>(2, INT_MIN)));

        for (int num:nums) {
            preSum.push_back(preSum.back() + num);
        }

        int ans = dfs(0, k, 0, nums, preSum);

        return ans;
    }
};

#include<iostream>
using namespace std;

class Solution {
public:
    int m, N;
    int dp[2001][2001][2];
    int dfs(int idx, int kleft, int canConnect, vector<int>& nums, vector<int>& preSum) {
        if (N-idx < kleft*m) return INT_MIN;
        if (idx == N) {
            if (kleft > 0) return INT_MIN;
            return 0;
        }

        int res = INT_MIN;

        // start a new subarray (with at least m elements)
        if (idx + m <= N) {
            if (kleft > 0) res = max(res, preSum[idx+m] - preSum[idx] + dfs(idx+m, kleft-1, 1, nums, preSum));
        }

        // add one element to previous subarray
        if (canConnect) {
            res = max(res, nums[idx] + dfs(idx+1, kleft, 1, nums, preSum));
        }

        // skip current element
        res = max(res, dfs(idx+1, kleft, 0, nums, preSum));

        return dp[idx][kleft][canConnect] = res;

    }

    int maxSum(vector<int>& nums, int k, int m) {
        this->m = m;
        this->N = nums.size();
        fill(&dp[0][0][0], &dp[0][0][0]+2001*2001*2, INT_MIN);
        vector<int> preSum = {0};
        for (int num:nums) {
            preSum.push_back(preSum.back() + num);
        }
        cout << "here" << endl;
        return dfs(0, k, 0, nums, preSum);
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1,2,-1,3,3,4};
    int k1 = 2, m1 = 2;
    cout << "here" << endl;
    cout << sol.maxSum(nums1, k1, m1) << endl;
}