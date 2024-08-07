class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        
        int cnt = 0;
        int last = -1;
        for (int i=0; i<points.size(); i++) {
            if (points[i][0] > last) {
                last = points[i][0] + w;
                cnt += 1;
            }
        }
        
        return cnt;
    }
};