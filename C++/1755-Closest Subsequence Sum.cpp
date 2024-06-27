class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int N = nums.size(), n = N/2, res = INT_MAX;
        vector<int> leftVal, rightVal;

        for (int state=0; state<(1<<n); state++) {
            int cnt = 0, leftSum = 0;
            for (int i=0; i<n; i++) {
                if ((state>>i) & 1) {
                    leftSum += nums[i];
                }
            }
            leftVal.push_back(leftSum);
        }

        for (int state=0; state<(1<<(N-n)); state++) {
            int cnt = 0, rightSum = 0;
            for (int i=0; i<(N-n); i++) {
                if ((state>>i) & 1) {
                    rightSum += nums[n+i];
                }
            }
            rightVal.push_back(rightSum);
        }

        sort(rightVal.begin(), rightVal.end());

        for (int val:leftVal) {
            auto it = lower_bound(rightVal.begin(), rightVal.end(), goal-val);
            if (it != rightVal.end()) {
                res = min(res, abs(val+(*it)-goal));
            }
            if (it != rightVal.begin()) {
                res = min(res, abs(val + *prev(it) - goal));
            }
            if (res == 0) return res;
        }
        return res;
    }
};