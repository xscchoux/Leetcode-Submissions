class Solution {
public:
    int k;
    bool isOK(vector<int>& arr, double diff) {
        // should have at least k+1 segments
        int cnt = 0;

        for (int num:arr) {
            cnt += (double)num/diff;
            if (cnt >= k+1) return true;
        }

        return false;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        this->k = k;
        vector<int> arr;

        for (int i=1; i<stations.size(); i++) {
            arr.push_back(stations[i]-stations[i-1]);
        }

        double left = 0, right = 1e8;
        while (left + 1e-6 < right) {
            double mid = left + (right-left)/2;
            if (isOK(arr, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isOK(arr, left)) {
            return left;
        }
        return right;
    }
};