class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int len = 1, N = nums.size();
        for (int i=N-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                len++;
            } else {
                break;
            }
        }

        return N-len;
    }
};