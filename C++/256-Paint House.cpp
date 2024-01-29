class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        for (int r=1; r<N; r++) {
            costs[r][0] += min(costs[r-1][1], costs[r-1][2]);
            costs[r][1] += min(costs[r-1][0], costs[r-1][2]);
            costs[r][2] += min(costs[r-1][0], costs[r-1][1]);
        }
        return *min_element(costs[N-1].begin(), costs[N-1].end());
    }
};