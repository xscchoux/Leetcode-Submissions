class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int case1 = 0;
        for (int i=1; i<nums.size(); i+=2){
            int mn = nums[i];
            if (i+1<nums.size() && nums[i+1] <= nums[i]) mn = nums[i+1] - 1;
            if (nums[i-1] <= nums[i]) mn = min(mn, nums[i-1] - 1);
            case1 += nums[i] - mn;
        }
        
        int case2 = 0;
        for (int i=0; i<nums.size(); i+=2){
            int mn = nums[i];
            if (i+1<nums.size() && nums[i+1] <= nums[i]) mn = nums[i+1] - 1;
            if (i-1>=0 && nums[i-1] <= nums[i]) mn = min(mn, nums[i-1] - 1);
            case2 += nums[i] - mn;
        }
        return min(case1, case2);
    }
};