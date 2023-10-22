class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;
        int res = nums[k], N = nums.size(), mn = nums[k];
        
        while (left >= 0 && right < N){
            int leftVal = 0, rightVal = 0;
            if (left - 1 >= 0) leftVal = nums[left-1];
            if (right + 1 < N) rightVal = nums[right+1];
            if (leftVal < rightVal){
                mn = min(mn, rightVal);
                right++;
            } else{
                mn = min(mn, leftVal);
                left--;
            }
            res = max(res, (right-left+1)*mn);
        }
        return res;
    }
};