class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> preSum;
        preSum[0] = -1;
        int curr = 0, res = 0;
        
        for (int i=0; i<nums.size(); i++) {
            curr += nums[i] == 1?1:-1;
            if (preSum.count(curr)) {
                res = max(res, i-preSum[curr]);
            } else {
                preSum[curr] = i;
            }
        }
        
        return res;
    }
};