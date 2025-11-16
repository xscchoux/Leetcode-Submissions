class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int N = nums.size();
        int res = 0;
        for (int i=0; i<N-2; i++) {
            int left = i+1, right = N-1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] >= target) {
                    right--;
                } else {
                    res += right-left;
                    left++;
                }
            }
        }

        return res;
    }
};