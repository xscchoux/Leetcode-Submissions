using LL = long long;
using PII = pair<int, int>;
class Solution {
public:
    bool isOK(int H, vector<int>& workerTimes, LL mid) {
        for (int t:workerTimes) {
            int times = ((-1+sqrt(1+8*(double)mid/t))/2);  // t*times*(times+1)/2 <= mid -> times = (-1 + (1+8*mid/t))/2
            H -= times;
            if (H <= 0) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int H, vector<int>& workerTimes) {
        LL res = 0;
        sort(begin(workerTimes), end(workerTimes));

        LL left = 0, right = (LL)H*(H+1)*workerTimes.back()/2;
        while (left + 1 < right) {
            LL mid = left + (right-left)/2;
            if (isOK(H, workerTimes, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(H, workerTimes, left)) {
            return left;
        }
        return right;
    }
};