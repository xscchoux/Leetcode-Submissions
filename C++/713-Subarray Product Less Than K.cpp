class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int current = 1, left = 0, res = 0;
        for (int i=0; i<nums.size(); i++) {
            current *= nums[i];
            while (left <= i && current >= k) {
                current = current/nums[left];
                left++;
            }
            res += i-left+1;
        }
        
        return res;
    }
};