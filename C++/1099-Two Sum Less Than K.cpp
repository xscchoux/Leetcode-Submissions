class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        int res = -1;
        while (left < right){
            if (nums[right] + nums[left] < k){
                res = max(res, nums[left]+nums[right]);
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int res = -1;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size() && nums[i]*2 < k; i++){
            // lower_bound points to the first element that is greater than or equal to the provided value.
            int j = lower_bound(nums.begin()+1, nums.end(), k-nums[i]) - nums.begin() - 1;   // j is the previous index of the element lower_bound points to 
            if (j > i) {
                res = max(res, nums[i]+nums[j]);
            }
        }
        return res;
    }
};