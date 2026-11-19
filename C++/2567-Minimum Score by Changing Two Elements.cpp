class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int N = nums.size();
        if (N == 3) return 0;

        sort(begin(nums), end(nums));

        return min({nums[N-1]-nums[2], nums[N-3]-nums[0], nums[N-2]-nums[1]});
    }
};