class Solution {
public:
    int getUpper(int limit, int k) {
        if (limit == 0) return 0;
        int left = 1, right = pow(limit, 1.0/k)+1;  // +1 to avoid floating-point precision issues

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            long long val = 1;
            for (int kk=1; kk<=k; kk++) {
                val = val*mid;
                if (val > 1e9) {
                    val = 1e9+1;
                    break;
                }
            }
            if (val > limit) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int rightVal = 1;
        for (int kk=1; kk<=k; kk++) {
            rightVal = rightVal*right;
        }
        if (rightVal <= limit) {
            return right;
        }
        return left;
    }
    int countKthRoots(int l, int r, int k) {
        if (k == 1) {
            return r-l+1;
        }

        int rBound = getUpper(r, k) + 1, lBound = (l == 0?0:(getUpper(l-1, k)+1));  // plus one because we need to consider '0'

        return rBound-lBound;
    }
};