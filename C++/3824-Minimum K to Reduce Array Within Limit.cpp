class Solution {
public:
    bool isOK(vector<int>& nums, long long k) {
        long long cnt = 0;
        for (int num:nums) {
            cnt += (num + k - 1)/k;
        }

        return cnt <= k*k;
    }
    int minimumK(vector<int>& nums) {
        long long left = 1, right = 1e5;

        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (isOK(nums, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, left)) {
            return left;
        }
        return right;
    }
};