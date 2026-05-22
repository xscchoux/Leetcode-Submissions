class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size(), left = 0, right = N-1;

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[left]) {  // left half is sorted
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else { // left half is not sorted, right half is sorted
                // check right half
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }

        if (nums[left] == target) {
            return left;
        } else if (nums[right] == target) {
            return right;
        } else {
            return -1;
        }
    }
};