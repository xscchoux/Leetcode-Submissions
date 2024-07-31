class Solution {
public:
    vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
        unordered_set<int> visited;
        int N = queries.size();
        vector<int> res;
        for (int i=N-1; i>=0; i--) {
            if (visited.contains(queries[i])) continue;
            res.push_back(queries[i]);
            visited.insert(queries[i]);
        }

        for (int w:windows) {
            if (!visited.contains(w)) {
                res.push_back(w);
            }
        }

        return res;
    }
};