// O(NlogN * k * klogk), k:indexes chosen
using PLV = pair<long long, vector<int>>;
class Solution {
public:
    int N;
    PLV dfs(int idx, int remain, vector<vector<int>>& intervals, vector<int>& nxtIdx, vector<vector<PLV>>& dp) {
        if (idx == N) {
            return {0, {}};
        }
        if (remain == 0) {
            return {0, {}};
        }
        if (dp[idx][remain].first != -1) {
            return dp[idx][remain];
        }

        // skip
        auto [points_skip, indexes_skip] = dfs(idx+1, remain, intervals, nxtIdx, dp);


        // take
        int nxt = nxtIdx[idx];
        auto [points_take, indexes_take] = dfs(nxt, remain-1, intervals, nxtIdx, dp);

        points_take += intervals[idx][2];
        indexes_take.push_back(intervals[idx][3]);
        sort(begin(indexes_take), end(indexes_take)); // at most 4 indexes, O(klogk)

        if (points_take > points_skip || (points_take == points_skip && indexes_take < indexes_skip)) {
            return dp[idx][remain] = {points_take, indexes_take};
        } else {
            return dp[idx][remain] = {points_skip, indexes_skip};
        }

    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        this->N = intervals.size();
        for (int i=0; i<N; i++) {
            intervals[i].push_back(i);
        }

        sort(begin(intervals), end(intervals));

        vector<int> nxtIdx(N, -1);
        for (int i=0; i<N; i++) {
            int endPos = intervals[i][1];
            vector<int> key = {endPos+1, 0, 0, 0};
            auto it = lower_bound(intervals.begin(), intervals.end(), key);
            if (it == end(intervals)) {
                nxtIdx[i] = N;
            } else {
                nxtIdx[i] = it-begin(intervals);
            }
        }

        vector<vector<PLV>> dp(N, vector<PLV>(5, {-1, vector<int>()}));
        auto res = dfs(0, 4, intervals, nxtIdx, dp);

        return res.second;
    }
};
