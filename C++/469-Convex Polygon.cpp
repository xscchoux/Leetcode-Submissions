class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        // cross product (pi+1-pi) x (pi+2-pi) does not change sign when traversing sequentially along polygon vertices
        int N = points.size();
        int pos = 0, neg = 0;
        for (int i=0; i<N; i++) {
            vector<int> vec1 = {points[(i+1)%N][0]-points[i][0], points[(i+1)%N][1]-points[i][1]};
            vector<int> vec2 = {points[(i+2)%N][0]-points[i][0], points[(i+2)%N][1]-points[i][1]};
            int det = vec1[0]*vec2[1] - vec2[0]*vec1[1];
            if ((pos|=(det>0))*(neg|=(det<0))) return false;  // if both negative det and positive det are found, return false;
        }
        return true;
    }
};