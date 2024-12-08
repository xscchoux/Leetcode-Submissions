class Solution {
public:
    bool isOK(vector<int>& ribbons, int k, int length) {
        int cnt = 0;
        for (int ribbon:ribbons) {
            cnt += ribbon/length;
            if (cnt >= k) return true;
        }
        return false;
    }
    int maxLength(vector<int>& ribbons, int k) {
        int N = ribbons.size();
        int left = 0, right = *max_element(begin(ribbons), end(ribbons));
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(ribbons, k, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isOK(ribbons, k, right)) {
            return right;
        }
        return left;
    }
};