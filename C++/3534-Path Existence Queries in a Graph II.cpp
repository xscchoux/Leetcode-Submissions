class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i=0; i<n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(begin(arr), end(arr));

        vector<int> rank(n);  // index to rank

        for (int i=0; i<n; i++) {  
            rank[arr[i].second] = i;
        }

        // 2^(maxBit-1) <= n < 2^maxBit
        int maxBit = bit_width((uint32_t)n);
        vector<vector<int>> dp(n, vector<int>(maxBit, 0)); // for binary lifting

        int right = 0;
        for (int i=0; i<n; i++) {
            while (right<n && arr[right].first - arr[i].first <= maxDiff) {
                right++;
            }
            dp[i][0] = right-1;
        }


        // binary lifting, dp[i][j] : the furthest node the ith node can reach within 2^j steps
        for (int j=1; j<maxBit; j++) {
            for (int i=0; i<n; i++) {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }

        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                res.push_back(0);
                continue;
            }
            
            u = rank[u];
            v = rank[v];
            if (u > v) {
                swap(u, v);
            }

            int step = 0;
            for (int k=maxBit-1; k>=0; k--) {
                if (dp[u][k] < v) {
                    step += (1<<k);
                    u = dp[u][k];
                }
            }
            if (dp[u][0] >= v) {
                res.push_back(step+1);
            } else {
                res.push_back(-1);
            }

        }

        return res;
    }
};