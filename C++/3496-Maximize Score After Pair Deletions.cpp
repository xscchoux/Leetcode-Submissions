class Solution {
public:
    int maxScore(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) return 0;
        
        int tot = accumulate(begin(nums), end(nums), 0);
        if (N%2) {
            return tot - *min_element(begin(nums), end(nums));
        } else {
            int minVal = INT_MAX;
            for (int i=0; i<N-1; i++) {
                minVal = min(minVal, nums[i]+nums[i+1]);
            }
            return tot - minVal;
        }
    }
};