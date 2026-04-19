class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int N = nums.size(), sm = INT_MAX;
        vector<int> smallest(N, INT_MAX);

        for (int i = N-1; i>=0; i--) {
            sm = min(sm, nums[i]);
            smallest[i] = sm;
        }

        int largest = 0;
        for (int i=0; i<N; i++) {
            largest = max(largest, nums[i]);
            if (largest - smallest[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};