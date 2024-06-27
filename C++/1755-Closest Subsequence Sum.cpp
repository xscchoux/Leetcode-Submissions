class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int N = nums.size(), n = N/2, res = INT_MAX;
        vector<int> leftVal = {0}, rightVal = {0};

        for (int i=0; i<n; i++) {
            for (int j=0, sz=leftVal.size(); j<sz; j++) {
                leftVal.push_back(leftVal[j]+nums[i]);
            }
        }

        for (int i=n; i<N; i++) {
            for (int j=0, sz=rightVal.size(); j<sz; j++) {
                rightVal.push_back(rightVal[j]+nums[i]);
            }
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