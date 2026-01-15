class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        int maxGapH = 1, currGapH = 1;
        for (int i=0; i<hBars.size(); i++) {
            if (i > 0 && hBars[i] == hBars[i-1] + 1) {
                currGapH++;
                maxGapH = max(maxGapH, currGapH);
            } else {
                currGapH = 1;
            }
        }


        int maxGapV = 1, currGapV = 1;
        for (int i=0; i<vBars.size(); i++) {
            if (i > 0 && vBars[i] == vBars[i-1] + 1) {
                currGapV++;
                maxGapV = max(maxGapV, currGapV);
            } else {
                currGapV = 1;
            }
        }

        int side = min(maxGapH+1, maxGapV+1);

        return side*side;
    }
};