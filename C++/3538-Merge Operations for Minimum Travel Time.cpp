class Solution {
public:
    int n, l, k;
    int dfs(int idx, int kRemain, int currTime, vector<int>& position, vector<int>& time, vector<vector<vector<int>>>& memo) {
        if (idx == n-1) {
            if (kRemain == 0) return 0;
            return INT_MAX/2;
        }

        if (memo[idx][kRemain][currTime] != -1) return memo[idx][kRemain][currTime];

        int res;
        // without merging
        res = (position[idx+1]-position[idx])*currTime + dfs(idx+1, kRemain, time[idx+1], position, time, memo);

        // merging
        if (kRemain > 0) {
            int nxtTime = time[idx+1];
            for (int nxtIdx = idx+2; nxtIdx <= min(n-1, idx+1+kRemain); nxtIdx++) {
                nxtTime += time[nxtIdx];
                res = min(res, (position[nxtIdx]-position[idx])*currTime + dfs(nxtIdx, kRemain - (nxtIdx-(idx+1)), nxtTime, position, time, memo));
            }
        }

        return memo[idx][kRemain][currTime] = res;
    }
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        int totTime = 0;
        this->n = n;
        this->l = l;  // this is NOT needed
        this->k = k;
        for (int t:time) totTime += t;

        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(k+1, vector<int>(totTime+1, -1)));
        return dfs(0, k, time[0], position, time, memo);
    }
};