class Solution {
public:
        int bs_left(vector<int>& nums, int target){
            int left = 0, right = nums.size()-1;
            while (left + 1 < right){
                int mid = left + (right-left)/2;
                if (nums[mid] < target)
                    left = mid;
                else
                    right = mid;
            }
            if (nums[left] == target) return left;
            else if (nums[right] == target) return right;
            else return -1;
        }

        int bs_right(vector<int>& nums, int target){
            int left = 0, right = nums.size()-1;
            while (left + 1 < right){
                int mid = left + (right-left)/2;
                if (nums[mid] <= target)
                    left = mid;
                else
                    right = mid;
            }
            if (nums[right] == target) return right;
            else if (nums[left] == target) return left;
            else return -1;
        }        
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        return {bs_left(nums, target), bs_right(nums, target)};
    }
};