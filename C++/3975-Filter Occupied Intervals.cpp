class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(begin(occupiedIntervals), end(occupiedIntervals), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> arr;
        int N = occupiedIntervals.size();

        for (int i=0; i<N; i++) {
            if (i == 0 || arr.back()[1] < occupiedIntervals[i][0]-1) {
                arr.push_back(occupiedIntervals[i]);
            } else {
                arr.back()[1] = max(arr.back()[1], occupiedIntervals[i][1]);
            }
        }

        vector<vector<int>> res;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i][0]>=freeStart && arr[i][1]<=freeEnd) { // occupied
                continue;
            } else if (arr[i][0] < freeStart && arr[i][1] > freeEnd) { // interval is inside arr[i]
                res.push_back({arr[i][0], freeStart-1});
                res.push_back({freeEnd+1, arr[i][1]});
            } else if (min(freeEnd, arr[i][1]) >= max(freeStart, arr[i][0])) { // overlapped
                if (arr[i][0] < freeStart) {
                    res.push_back({arr[i][0], freeStart-1});
                } else {
                    res.push_back({freeEnd+1, arr[i][1]});
                }
            } else {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};