using LL = long long;
using TLIII = tuple<LL, int, int, int>; 
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        int row = m, col = n;
        priority_queue<TLIII, vector<TLIII>, greater<>> pq;

        vector<vector<vector<LL>>> dist(row, vector<vector<LL>>(col, vector<LL>(2, LLONG_MAX)));

        dist[0][0][1] = 1;

        pq.push({1, 0, 0, 1});

        while (!pq.empty()) {
            auto [d, r, c, actionNum] = pq.top();
            pq.pop();
            
            if (dist[r][c][actionNum] < d) continue;

            if (r == row-1 && c == col-1) {
                return d;
            }
            // wait
            if (d + penalty[r][c] < dist[r][c][1-actionNum]) {
                dist[r][c][1-actionNum] = d + penalty[r][c];
                pq.emplace(d+penalty[r][c], r, c, 1-actionNum);
            }
            // right
            if (c+1 < col) {
                LL newCost = d + (r+1)*(c+1+1) + (actionNum == 1?0:1)*penalty[r][c];
                if (newCost < dist[r][c+1][1-actionNum]) {
                    dist[r][c+1][1-actionNum] = newCost;
                    pq.emplace(newCost, r, c+1, 1-actionNum);
                }
            }
            // down
            if (r+1 < row) {
                LL newCost = d + (r+1+1)*(c+1) + (actionNum == 1?0:1)*penalty[r][c];
                if (newCost < dist[r+1][c][1-actionNum]) {
                    dist[r+1][c][1-actionNum] = newCost;
                    pq.emplace(newCost, r+1, c, 1-actionNum);
                }
            }
            // left
            if (c-1 >= 0) {
                LL newCost = d + (r+1)*(c-1+1) + (actionNum == 0?0:1)*penalty[r][c];
                if (newCost < dist[r][c-1][1-actionNum]) {
                    dist[r][c-1][1-actionNum] = newCost;
                    pq.emplace(newCost, r, c-1, 1-actionNum);
                }
            }
            // up
            if (r-1 >= 0) {
                LL newCost = d + (r-1+1)*(c+1) + (actionNum == 0?0:1)*penalty[r][c];
                if (newCost < dist[r-1][c][1-actionNum]) {
                    dist[r-1][c][1-actionNum] = newCost;
                    pq.emplace(newCost, r-1, c, 1-actionNum);
                }
                 
            }
        }


        return -1;

    }
};