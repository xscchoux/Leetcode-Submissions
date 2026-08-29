class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        auto it = lower_bound(begin(nums), end(nums), lower);        

        if (it == nums.end()) {
            if (nums.back() == lower) {
                return {{min(lower+1, upper), upper}};
            } else {
                return {{lower, upper}};
            }
        }

        vector<vector<int>> res;
        int idx = it - begin(nums);
        if (lower < nums[idx]) {
            res.push_back({lower, min(nums[idx]-1, upper)});
        }

        if (upper < nums[idx]) return res;

        int lastIdx = idx;
        for (int i = idx; i<nums.size()-1 && upper > nums[i+1]; i++) {
            if (nums[i+1] - nums[i] > 1)
                res.push_back({nums[i]+1, nums[i+1]-1});
            lastIdx = i+1;
        }

        if (upper > nums[lastIdx]) {
            if (lastIdx + 1 < nums.size() && nums[lastIdx+1] == upper) {
                upper = upper-1;
            }
            if (upper - nums[lastIdx] + 1 > 1) {
                res.push_back({nums[lastIdx]+1, upper});
            }
            
        }

        return res;
    }
};