using LL = long long;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int N = bottomLeft.size();
        int res = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (i==j) continue;
                const int diffX = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                const int diffY = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                if (diffX > 0 && diffY > 0) res = max(res, min(diffX, diffY));
            }
        }
        return LL(res) * res;
    }
};