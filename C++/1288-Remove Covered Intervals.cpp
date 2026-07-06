class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](auto &a, auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int N = intervals.size();

        int res = 0, endPos = -1;

        for (int i=0; i<N; i++) {
            if (intervals[i][1] > endPos) {
                endPos = intervals[i][1];
                res++;
            }
        }

        return res;
    }
};