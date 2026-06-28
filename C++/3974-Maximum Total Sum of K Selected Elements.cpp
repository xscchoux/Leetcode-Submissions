class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(begin(nums), end(nums), greater<>());

        long long sum = 0;
        for (int i=0; i<k; i++) {
            if (mul > 1) {
                sum += (long long)nums[i]*mul;
                mul--;
            } else {
                sum += nums[i];
            }
        }

        return sum;
    }
};