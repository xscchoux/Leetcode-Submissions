// O(n*k*k), first try
class Solution {
public:
    int n, k;
    vector<vector<int>> memo;
    int cal(int r, int prevC, vector<vector<int>>& costs) {
        if (r == n) return 0;
        if (memo[r][prevC] != -1) return memo[r][prevC];
        int mn1 = INT_MAX, idx1 = -1, mn2 = INT_MAX, idx2 = -1;
        for (int c=0; c<k; c++) {
            if (c == prevC) continue;
            if (costs[r][c] < mn1) {
                mn2 = mn1;
                idx2 = idx1;
                mn1 = costs[r][c];
                idx1 = c;
            } else if (costs[r][c] < mn2) {
                mn2 = costs[r][c];
                idx2 = c;
            }
        }

        int res = INT_MAX;
        res = mn1 + cal(r+1, idx1, costs);
        if (mn2 != INT_MAX) {
            res = min(res, mn2 + cal(r+1, idx2, costs));
        }
        return memo[r][prevC] = res;
    }
    int minCostII(vector<vector<int>>& costs) {
        n = costs.size();
        k = costs[0].size();
        int res = INT_MAX;
        memo.resize(n, vector<int>(k, -1));
        for (int c = 0; c < k; c++) {
            res = min(res, costs[0][c] + cal(1, c, costs));
        }
        return res;
    }
};



// O(n*k), really smart solution
class Solution {
public:
    int n, k;
    int minCostII(vector<vector<int>>& costs) {
        n = costs.size();
        k = costs[0].size();
        for (int r=1; r<n; r++) {
            int mn1 = INT_MAX, mn2 = INT_MAX;
            for (int c=0; c<k; c++) {
                if (costs[r-1][c] < mn1) {
                    mn2 = mn1;
                    mn1 = costs[r-1][c];
                } else if (costs[r-1][c] < mn2) {
                    mn2 = costs[r-1][c];
                }
            }
            for (int c=0; c<k; c++) {
                if (costs[r-1][c] == mn1) {
                    costs[r][c] += mn2;
                } else {
                    costs[r][c] += mn1;
                }
            }
        }
        return *min_element(begin(costs.back()), end(costs.back()));
    }
};