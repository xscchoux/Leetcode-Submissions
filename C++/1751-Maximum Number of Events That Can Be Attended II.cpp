// First AC
class Solution {
public:
    int N;
    int bs(int time, vector<vector<int>>& events) {
        int left = 0, right = events.size()-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (events[mid][0] > time) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (events[left][0] > time) {
            return left;
        } else if (events[right][0] > time) {
            return right;
        } else {
            return -1;
        }
    }
    int dfs(int idx, vector<vector<int>>& events, int remainK, vector<vector<int>>& memo) {
        if (remainK == 0 || idx == N) {
            return 0;
        }

        if (memo[idx][remainK] != -1) return memo[idx][remainK];

        int res = 0;
        // no pick
        res = max(res, dfs(idx+1, events, remainK, memo));

        // pick
        int nxtIdx = bs(events[idx][1], events);
        if (nxtIdx == -1) {
            res = max(res, events[idx][2]); 
        } else {
            res = max(res, events[idx][2] + dfs(nxtIdx, events, remainK-1, memo));
        }

        return memo[idx][remainK] = res;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        this->N = events.size();
        sort(begin(events), end(events), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> memo(N, vector<int>(k+1, -1));

        return dfs(0, events, k, memo);
    }
};

// Concise, but not faster
class Solution {
public:
    int N;
    vector<int> next;
    vector<vector<int>> memo;
    int dfs(int idx, vector<vector<int>>& events, int remainK) {
        if (remainK == 0 || idx == N) {
            return 0;
        }

        if (memo[idx][remainK] != -1) return memo[idx][remainK];

        // skip
        int res = dfs(idx+1, events, remainK);

        // pick
        int nxtIdx = next[idx];
        res = max(res, events[idx][2] + dfs(nxtIdx, events, remainK-1));

        return memo[idx][remainK] = res;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        this->N = events.size();
        sort(begin(events), end(events), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        
        memo.assign(N, vector<int>(k+1, -1));
        next.assign(N, N);

        for (int i=0; i<N; i++) {
            next[i] = upper_bound(begin(events), end(events), vector<int>{events[i][1]+1, 0, 0}) - begin(events);
        }

        return dfs(0, events, k);
    }
};