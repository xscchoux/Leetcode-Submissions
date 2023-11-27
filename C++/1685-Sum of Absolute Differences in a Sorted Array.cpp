class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int N = nums.size();
        int leftSum = 0;
        vector<int> res;
        
        for (int i=0; i<nums.size(); i++){
            int rightSum = tot - leftSum - nums[i];
            
            int left = nums[i]*i - leftSum;
            int right = rightSum - nums[i]*(N-i-1);
            
            res.push_back(left + right);
            leftSum += nums[i];
        }
        
        return res;
    }
};