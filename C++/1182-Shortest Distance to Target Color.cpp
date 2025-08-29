class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> pos;
        int Nq = queries.size();

        for (int i=0; i<colors.size(); i++) {
            pos[colors[i]].push_back(i);
        }

        vector<int> res;

        for (auto &q:queries) {
            int color = q[1], ans = INT_MAX;
            auto it = lower_bound(begin(pos[color]), end(pos[color]), q[0]);

            if (it != end(pos[color])) ans = (*it - q[0]);
            if (it != begin(pos[color])) ans = min(ans, q[0] - *(--it));
            
            if (ans == INT_MAX) res.push_back(-1);
            else res.push_back(ans);
        }
        return res;
    }
};