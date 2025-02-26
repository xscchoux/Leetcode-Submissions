class Solution {
public:
    double cal(vector<vector<int>>& squares, double mid) {
        double area = 0;
        for (auto &square:squares) {
            int x = square[0], y = square[1], w = square[2];
            if (y > mid) continue;
            area += w*(min((double)y+w, mid) - y);
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int yMax = 0;
        double tot = 0;
        for (auto &square:squares) {
            int x = square[0], y = square[1], w = square[2];
            yMax = max(yMax, y+w);
            tot += (double)w*w;
        }

        tot /= 2;

        double left = 0, right = yMax, diff = 0.00001;
        while (left + diff < right) {
            double mid = (left + right)/2;
            if (cal(squares, mid) < tot) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return right;
    }
};