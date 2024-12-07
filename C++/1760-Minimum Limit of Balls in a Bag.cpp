class Solution {
public:
    bool isOK(vector<int>& nums, int maxOperations, int smallest) {
        int op = 0;
        for (int num:nums) {
            int diff = num - smallest;
            if (diff <= 0) continue;
            op += (diff/smallest) + (diff%smallest?1:0);
            if (op > maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(begin(nums), end(nums));
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(nums, maxOperations, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isOK(nums, maxOperations, right)) {
            return right;
        }
        return left;
    }
};