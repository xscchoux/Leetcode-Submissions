class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](auto &a, auto &b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        int res = 2, N = intervals.size();
        int two = intervals[0].back(), one = two-1;

        for (int i=1; i<N; i++) {
            if (intervals[i][0] > two) {
                res += 2;
                two = intervals[i].back();
                one = two-1;
            } else if ( two >= intervals[i][0] && one < intervals[i][0]) {
                res++;
                one = two;
                two = intervals[i].back();
            }
        }

        return res;
    }
};