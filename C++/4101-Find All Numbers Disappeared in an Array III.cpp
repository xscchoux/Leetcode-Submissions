class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));

        if (lower > nums.back() || upper < nums[0]) {
            return {{lower, upper}};
        }

        vector<vector<int>> res;

        int N = nums.size();
        for (int i=0; i<N; i++) {
            if (lower < nums[i]) {
                int currEnd = min(upper, nums[i]-1);
                if (currEnd >= lower) {
                    res.push_back({lower, currEnd});
                }    
            }
            lower = max(lower, nums[i]+1);
        }

        if (upper >= lower) {
            res.push_back({lower, upper});
        }

        return res;
    }
};