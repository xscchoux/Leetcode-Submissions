// First AC
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // vertical cuts
        vector<vector<int>> arr;
        for (auto &r:rectangles) {
            int u = r[0], v = r[2];
            arr.push_back({u, v});
        }

        sort(begin(arr), end(arr));

        // merge intervals
        vector<vector<int>> intervals;
        intervals.push_back(arr[0]);
        for (int i=1; i<arr.size(); i++) {
            int u = arr[i][0], v = arr[i][1];
            if (u < intervals.back()[1]) {
                intervals.back()[1] = max(intervals.back()[1], v);
            } else {
                intervals.push_back(arr[i]);
            }
        }
        if (intervals.size() >= 3) return true;



        // horizontal cuts
        vector<vector<int>> arr2;
        for (auto &r:rectangles) {
            int u = r[1], v = r[3];
            arr2.push_back({u, v});
        }

        sort(begin(arr2), end(arr2));

        // merge intervals
        vector<vector<int>> intervals2;
        intervals2.push_back(arr2[0]);
        for (int i=1; i<arr2.size(); i++) {
            int u = arr2[i][0], v = arr2[i][1];
            if (u < intervals2.back()[1]) {
                intervals2.back()[1] = max(intervals2.back()[1], v);
            } else {
                intervals2.push_back(arr2[i]);
            }
        }
        if (intervals2.size() >= 3) return true;
        return false;
    }
};



// Same idea but faster. Using vector<pair<int, int>> is faster than vector<vector<int>> 
// Each pair<int, int> is stored as a contiguous block of memory. For example, the two ints in a pair are directly adjacent in memory.
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // vertical cuts
        vector<pair<int, int>> arrX, arrY;
        for (auto &r:rectangles) {
            int x1 = r[0], x2 = r[2], y1 = r[1], y2 = r[3];
            arrX.push_back({x1, x2});
            arrY.push_back({y1, y2});
        }

        sort(begin(arrX), end(arrX));

        // merge intervals
        int endX = arrX[0].second, xIntervals = 1;
        for (int i=1; i<arrX.size(); i++) {
            int u = arrX[i].first, v = arrX[i].second;
            if (u < endX) {
                endX = max(endX, v);
            } else {
                xIntervals++;
                endX = v;
            }
        }
        if (xIntervals >= 3) return true;

        // horizontal cuts
        sort(begin(arrY), end(arrY));

        // merge intervals
        int endY = arrY[0].second, yIntervals = 1;
        for (int i=1; i<arrY.size(); i++) {
            int u = arrY[i].first, v = arrY[i].second;
            if (u < endY) {
                endY = max(endY, v);
            } else {
                yIntervals++;
                endY = v;
            }
        }
        if (yIntervals >= 3) return true;
        return false;
    }
};