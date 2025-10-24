class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int N = nums.size(), res = 0;
        for (int start = 0; start < N; start++) {
            unordered_set<int> evenSet, oddSet;
            for (int i=start; i<N; i++) {
                if (nums[i]%2) {
                    oddSet.insert(nums[i]);
                } else {
                    evenSet.insert(nums[i]);
                }
                if (oddSet.size() == evenSet.size()) {
                    res = max(res, i-start+1);
                }
            }
        }
        return res;
    }
};