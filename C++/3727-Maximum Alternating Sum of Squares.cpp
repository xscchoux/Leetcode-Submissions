class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(begin(nums), end(nums), [](int a, int b) {
            return abs(a) < abs(b);
        });

        long long res = 0;
        int left = 0, right = nums.size()-1, flag = 1;

        while (left <= right) {
            if (flag) {
                res += nums[right]*nums[right];
                right--;
            } else {
                res -= nums[left]*nums[left];
                left++;
            }
            flag = 1-flag;
        }

        return res;
    }
};