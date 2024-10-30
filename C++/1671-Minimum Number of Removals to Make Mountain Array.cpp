class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size(), length = 0;
        vector<int> left(N, 1);
        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], 1+left[j]);
                }
            }
        }

        vector<int> right(N, 1);
        for (int i=N-1; i>=0; i--) {
            for (int j=N-1; j>i; j--) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], 1+right[j]);
                }
            }
        }

        for (int i=1; i<N-1; i++) {
            if (left[i] == 1 || right[i] == 1) continue;
            length = max(length, left[i]+right[i]-1);
        }

        return N-length;
    }
};