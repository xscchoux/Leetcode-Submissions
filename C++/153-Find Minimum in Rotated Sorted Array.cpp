class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int N = nums.size();

        // when N == 1 or nums[N-1] > nums[0]
        if (nums[N-1] >= nums[0]) return nums[0];

        // find the first element < nums[0]
        int left = 0, right = N-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        if (nums[left] < nums[0]) {
            return nums[left];
        }
        return nums[right];
    }
};