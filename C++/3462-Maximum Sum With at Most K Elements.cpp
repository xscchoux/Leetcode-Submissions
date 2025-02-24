class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> pq;
        int rowIdx = 0, n = grid[0].size();
        for (auto &g:grid) {
            sort(begin(g), end(g), greater<>());
            for (int i=0; i<min(n, limits[rowIdx]); i++) {
                pq.push(g[i]);
            }
            rowIdx++;
        }
        long long res = 0;
        while (!pq.empty() && k-- > 0) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};