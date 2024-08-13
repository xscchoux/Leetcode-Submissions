class Solution {
public:
    int N;
    void dfs(int start, vector<int>& curr, vector<vector<int>>& res, vector<int>& candidates, int remain) {
        if (remain == 0) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i<N; i++) {
            if (remain < candidates[i]) break;
            if (i == start || candidates[i] != candidates[i-1]) { // pruning, avoid duplicate cases
                curr.push_back(candidates[i]);
                // dfs(i+1, curr + {candidates[i]}, res, candidates, remain-candidates[i]);   // cannot do this
                dfs(i+1, curr, res, candidates, remain-candidates[i]);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->N = candidates.size();
        sort(candidates.begin(), candidates.end()); // sort for pruning
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, curr, res, candidates, target);

        return res;
    }
};