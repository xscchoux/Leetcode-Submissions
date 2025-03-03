class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int N = nums.size(), left = 0, right = N-1;
        vector<int> res(N);

        for (int i=0; i<N; i++) {
            if (nums[i] < pivot) {
                res[left++] = nums[i];
            }
            if (nums[N-i-1] > pivot) {
                res[right--] = nums[N-i-1];
            }
        }

        while (right >= left) {
            res[left] = pivot;
            left++;
        }

        return res;
    }
};