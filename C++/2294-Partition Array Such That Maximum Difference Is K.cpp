class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 0, N = nums.size();
        int j = 0, i = 0;
        
        while ( i < N ) {
            int curr = i;
            while (j < N && nums[j] - nums[curr] <= k) {
                j++;
            }
            res++;
            i = j;
        }

        return res;
    }
};