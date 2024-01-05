class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        
        for (int i=1; i<N; i++){
            for (int j=0; j<i; j++){
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp;
        
        for (int i=0; i<N; i++) {
            if (dp.empty() || nums[i] > dp[dp.size()-1]){
                dp.push_back(nums[i]);
            } else {
                int first_not_smaller = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[first_not_smaller] = nums[i];
            }
        }
        return dp.size();
    }
};