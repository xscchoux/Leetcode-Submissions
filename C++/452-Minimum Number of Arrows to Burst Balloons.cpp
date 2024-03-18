class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int N = points.size();
        int res = 1;
        
        int firstEnd = points[0][1];
        for (int i=0; i<N; i++) {
            int s = points[i][0], e = points[i][1];
            if (s <= firstEnd) {
                firstEnd = min(firstEnd, points[i][1]);
            } else {
                res++;
                firstEnd = e;
            }
        }
        return res;
    }
};