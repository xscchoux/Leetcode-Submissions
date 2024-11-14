class Solution {
public:
    bool isOK(vector<int>& quantities, int mx, int n) {
        int count = 0;
        for (int q:quantities) {
            count += (q+mx-1)/mx;
        }
        return count <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(begin(quantities), end(quantities));
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(quantities, mid, n)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isOK(quantities, left, n)) {
            return left;
        }
        return right;
    }
};