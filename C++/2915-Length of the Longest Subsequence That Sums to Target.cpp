class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp = vector(target+1, 0);
        
        for (int i=0; i<nums.size(); i++){
            for (int j=target; j>=nums[i]; j--){
                if (dp[j-nums[i]] || j-nums[i] == 0){
                    dp[j] = max(dp[j], dp[j-nums[i]] + 1);
                }
            }
        }
        return dp[dp.size()-1] > 0 ? dp[dp.size()-1] : -1;
    }
};