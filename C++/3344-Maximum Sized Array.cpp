using LL = long long;
class Solution {
public:
    bool cal(long long n, long long s) {
        long long tot = 0;
        long long iSum = (n*(n-1))/2;

        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                tot += iSum*(j|k);
                if (tot > s) {
                    return true;
                }
            }
        }

        return false;
    }
    int maxSizedArray(long long s) {
        long long mx = sqrt(s);
        LL left = 0, right = mx+1;  // actually mx+1 is too large, 1196 is the largest n with sum <= 10^15, we can also precompute the upperbound first

        while (left + 1 < right) {
            LL mid = left + (right-left)/2;
            if (cal(mid, s)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (!cal(right, s)) {
            return right;
        }
        return left;
    }
};