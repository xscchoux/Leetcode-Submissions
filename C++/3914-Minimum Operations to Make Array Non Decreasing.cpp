class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int N = nums.size();
        long long res = 0;
        for (int i=1; i<N; i++) {
            if (nums[i] < nums[i-1]) {
                res += nums[i-1] - nums[i];
            }
        }

        return res;
    }
};