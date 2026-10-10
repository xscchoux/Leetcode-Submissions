class Solution {
public:
    bool isOK(int maxDiff, vector<int>& diff, int k) {
        for (int i=0; i<diff.size(); i++) {
            if (diff[i] > maxDiff) {
                k -= (diff[i]-maxDiff);
            }
            if (k < 0) return false;
        }

        return true;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int N = nums1.size(), k = k1 + k2, maxDiff = 0;

        vector<int> diff;

        for (int i=0; i<N; i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            maxDiff = max(d, maxDiff);
        }
        
        int left = 0, right = maxDiff;   // find minimum max difference

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(mid, diff, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int minimaxDiff;
        if (isOK(left, diff, k)) {
            minimaxDiff = left;
        } else {
            minimaxDiff = right;
        }
        
        for (int i=0; i<N; i++) {
            if (diff[i] > minimaxDiff) {
                k -= diff[i] - minimaxDiff;
                diff[i] = minimaxDiff;
            }
        }

        long long res = 0;
        for (int i=0; i<N; i++) {
            if (diff[i] < minimaxDiff) {
                res += (long long)diff[i]*diff[i];
            } else {
                if (k > 0) {
                    k -= 1;
                    int currDiff = max(0, minimaxDiff-1);
                    res += (long long)currDiff*currDiff;
                } else {
                    res += (long long)minimaxDiff*minimaxDiff;
                }
            }
        }

        return res;
    }
};