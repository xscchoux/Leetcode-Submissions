class Solution {
    vector<vector<int>> res;
    int N;
public:
    void dfs(int idx, vector<int>& arr, vector<int>& nums) {
        if (idx == N) {
            res.push_back(arr);
            return;
        }
        dfs(idx+1, arr, nums);
        arr.push_back(nums[idx]);
        dfs(idx+1, arr, nums);
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        vector<int> arr;
        dfs(0, arr, nums);
        return res;
    }
};