class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        // pick j, dp[i] >= dp[j], where dp[i] = presum[i] - presum[j]
        // presum[i] - presum[j] >= dp[j]
        // presum[i] >= dp[j] + presum[j]
        // keep a monotonic increasing stack of {dp[i1]+presum[i1], dp[i2]+presum[i2], ...} 
        
        int N = nums.size();
        vector<int> length(N, 0);
        length[0] = 1;
        vector<int> dp(N, 0);
        dp[0] = nums[0];
        
        vector<long> preSum = {nums[0]};
        for (int i=1; i<N; i++){
            preSum.push_back(preSum[preSum.size()-1] + nums[i]);
        }
        vector<pair<long, int>> stack = {{2*nums[0], 0}};
        
        
        for (int i=1; i<N; i++){
            auto it = upper_bound(stack.begin(), stack.end(), make_pair(preSum[i], INT_MAX));
            if (it!=stack.begin()){
                int j = prev(it)->second;
                dp[i] = preSum[i] - preSum[j];
                length[i] = length[j] + 1;
            } else {
                dp[i] = preSum[i];
                length[i] = 1;                
            }
            while (!stack.empty() && stack[stack.size()-1].first >= dp[i]+preSum[i]){
                stack.pop_back();
            }
            stack.push_back({dp[i] + preSum[i], i});
        }

        return length[length.size()-1];
    }
};