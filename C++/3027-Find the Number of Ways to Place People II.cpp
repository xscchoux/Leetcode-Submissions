class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto &a, const auto &b){
            return a[0]<b[0]||(a[0] == b[0] && a[1] > b[1]);
        });

        int res = 0;

        for (int i=0; i<points.size(); i++) {
            int upperLeft = points[i][1], lastY = -1e9-1;
            for (int j=i+1; j<points.size(); j++) {
                int bottomRight = points[j][1];
                if (bottomRight > upperLeft) continue;
                if (bottomRight > lastY) {
                    lastY = bottomRight;
                    res++;
                }
            }
        }

        return res;
    }
};