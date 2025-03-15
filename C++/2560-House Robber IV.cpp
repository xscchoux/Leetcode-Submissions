class Solution {
public:
    int k, N;
    bool isOK(vector<int>& nums, int maxVal) {
        int cnt = 0;

        for (int i=0; i<N; i++) {
            if (nums[i] <= maxVal) {
                if (++cnt >= k) return true;
                i++;
            }
        }

        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        this->k = k;
        this->N = nums.size();
        int mn = INT_MAX, mx = 0;
        for (int i=0; i<N; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        int left = mn, right = mx;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (isOK(nums, left)) {
            return left;
        }
        return right;
    }
};