// See the math trick from this link:
// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/solutions/6594072/python-o-n-2-dp-math-trick-o-n-log-n-with-cht/
class Solution {
public:
    int k, N;
    long long dfs(int idx, vector<long long>& preSum, vector<long long>& suffixCost, vector<long long>& memo) {
        if (idx >= N) return 0;

        if (memo[idx] != -1) return memo[idx];

        long long res = LLONG_MAX;
        for (int end = idx; end < N; end++) {
            long long numsPart = preSum[end]*(suffixCost[idx] - ((end == N-1)?0:suffixCost[end+1]));
            long long costPart = k*suffixCost[idx];
            res = min(res, numsPart + costPart + dfs(end+1, preSum, suffixCost, memo));
        }

        return memo[idx] = res;
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        this->k = k;
        this->N = nums.size();
        vector<long long> preSum(N, 0);
        vector<long long> suffixCost(N, 0);
        vector<long long> memo(N, -1);

        preSum[0] = nums[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }

        suffixCost[N-1] = cost.back();
        for (int i=N-2; i>=0; i--) {
            suffixCost[i] = suffixCost[i+1] + cost[i];
        }

        return dfs(0, preSum, suffixCost, memo);
    }
};