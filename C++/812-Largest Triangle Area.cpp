class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        int res = 0;
        for (int i=0; i<=N-3; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j=i+1; j<=N-2; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                for (int k=j+1; k<=N-1; k++) {
                    int x3 = points[k][0], y3 = points[k][1];
                    res = max(res, abs(x1*y2-x2*y1 + x2*y3-x3*y2 + x3*y1-x1*y3));
                }
            }
        }
        return 0.5*res;
    }
};