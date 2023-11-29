class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int res = 0;
        int currZero = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0) currZero++;
            if (currZero > 1){
                if (nums[left] == 0){
                    currZero--;
                }
                left++;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};