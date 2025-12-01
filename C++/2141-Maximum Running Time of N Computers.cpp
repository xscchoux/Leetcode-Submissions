class Solution {
public:
    bool canReach(long long time, int n, vector<int>& batteries) {
        long long batteryTime = 0;
        for (long long b:batteries) {
            batteryTime += min(b, time);
        }

        return batteryTime >= time*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = *min_element(begin(batteries), end(batteries));
        long long tot = accumulate(begin(batteries), end(batteries), 0LL);  // use 0LL, or we'll have runtime error
        long long right = tot/n;

        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (canReach(mid, n, batteries)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (canReach(right, n, batteries)) {
            return right;
        }
        return left;
    }
};