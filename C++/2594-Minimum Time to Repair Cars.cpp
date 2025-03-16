class Solution {
public:
    int Ncars;
    bool isOK(vector<int>& ranks, long long maxTime) {
        int car = 0;
        for (int r:ranks) {
            car += sqrt(maxTime/r);
            if (car >= Ncars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        this->Ncars = cars;

        int mn = *min_element(begin(ranks), end(ranks));

        long long left = 1, right = (long long)mn*cars*cars;
        while (left +1 < right) {
            long long mid = left + (right-left)/2;
            if (isOK(ranks, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(ranks, left)) {
            return left;
        }
        return right;
    }
};