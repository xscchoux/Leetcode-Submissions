class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N+2, 0);
        
        for (int i=0; i<N; i++) {
            res[i+2] = max(res[i+1], res[i] + nums[i]);
        }
        
        return res[N+1];
    }
};