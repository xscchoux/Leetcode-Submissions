class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int N = nums.size();
        unordered_set<int> toChange;

        for (int i=0; i<N; i++) {
            if (nums[i] != target[i]) {
                toChange.insert(nums[i]);
            }
        }

        return toChange.size();
    }
};