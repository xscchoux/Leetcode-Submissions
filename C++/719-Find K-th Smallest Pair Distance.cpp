class Solution {
public:
    int k;
    int isOK(vector<int>& nums, int target) {
        int left=0, cnt=0;
        for (int i=1; i<nums.size(); i++) {
            while (nums[i] - nums[left] > target) {
                left++;
            }
            cnt += i-left;
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        this->k = k;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, left)) return left;
        return right;
    }
};