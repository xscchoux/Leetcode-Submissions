class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<double, vector<double>> slopeToIntercept;
        unordered_map<int, vector<double>> midToSlope;

        for (int i=0; i<N; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j=0; j<i; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                double slope, intercept;
                if (x1 == x2) {
                    slope = 1e5;
                    intercept = x1;   // tricky here. It just needs to be different for different lines; the real intercept isn't needed.
                } else {
                    slope = (double)(y2-y1)/(x2-x1);
                    // intercept = y1 - x1*slope;  // This doesn't work because you multiply the slope error, making the intercept even more different
                    intercept = (double)(y1 * (x2-x1) - x1 * (y2-y1)) / (x2-x1);
                }
                slopeToIntercept[slope].push_back(intercept);
                int mid = (x1+x2)*10000 + (y1+y2);
                midToSlope[mid].push_back(slope);
            }
        }

        int res = 0;
        
        // Note that all parallelograms are counted twice because one parallelogram has two pairs of parallel lines
        for (auto &[_, interceptVec]:slopeToIntercept) {
            if (interceptVec.size() == 1) continue;
            
            unordered_map<double, int> cnt;
            for (double intercept:interceptVec) cnt[intercept]++;

            int sum = 0;
            for (auto &[_, count]:cnt) {
                res += count*sum;
                sum += count;
            }
        }

        // Remove the number of parallelogram once
        for (auto &[_, slopeVec]:midToSlope) {
            if (slopeVec.size() == 1) continue;
            
            unordered_map<double, int> cnt;
            for (double slope:slopeVec) cnt[slope]++;

            int sum = 0;
            for (auto &[_, count]:cnt) {
                res -= count*sum;
                sum += count;
            }
        }

        return res;
    }
};