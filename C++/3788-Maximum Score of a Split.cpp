class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int N = nums.size();
        vector<int> minArr(N, INT_MAX);
        for (int i=N-2; i>=0; i--) {
            minArr[i] = min(minArr[i+1], nums[i+1]);
        }

        long long curr = 0, res = LLONG_MIN;
        for (int i=0; i<nums.size()-1; i++) {
            curr += nums[i];
            res = max(res, curr - minArr[i]);
        }

        return res;
    }
};