class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int N = arr.size(), left = 0, right = N-1;
        // note numbers are distinct
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (arr[mid] < mid) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (arr[left] == left) {
            return left;
        } else if (arr[right] == right) {
            return right;
        } else {
            return -1;
        }

    }
};