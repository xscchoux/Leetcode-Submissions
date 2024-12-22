class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<vector<int>> arr;
        for (int i=0; i<queries.size(); i++) {
            auto [u, v] = minmax(queries[i][0], queries[i][1]); // sort the 
            arr.push_back({u, v, i});
        }
        sort(begin(arr), end(arr), [&](vector<int>& a, vector<int>& b) {
            return max(a[0], a[1]) < max(b[0], b[1]);
        });

        int N = heights.size(), i = N-1, dqIdx = arr.size()-1;
        deque<pair<int, int>> dq;   // {value, index}
        vector<int> res(queries.size(), 0);

        while (i >= 0) {
            while (!dq.empty() && heights[i] >= dq.front().first) {
                dq.pop_front();
            }
            dq.push_front({heights[i], i});
            while (dqIdx >= 0 && max(arr[dqIdx][0], arr[dqIdx][1]) == i) {
                auto it = dq.end();
                if ( (heights[arr[dqIdx][0]] == heights[arr[dqIdx][1]] && arr[dqIdx][0] != arr[dqIdx][1]) || (heights[arr[dqIdx][0]] > heights[arr[dqIdx][1]] ) ) {
                    it = upper_bound(dq.begin(), dq.end(), make_pair(max(heights[arr[dqIdx][0]], heights[arr[dqIdx][1]]), INT_MAX));
                }
                else {
                    it = lower_bound(dq.begin(), dq.end(), make_pair(max(heights[arr[dqIdx][0]], heights[arr[dqIdx][1]]), INT_MIN));
                }

                if (it == dq.end()) res[arr[dqIdx][2]] = -1;
                else {
                    res[arr[dqIdx][2]] = it->second;
                }
                dqIdx--;
            }
            i--;
        }

        return res;
    }
};