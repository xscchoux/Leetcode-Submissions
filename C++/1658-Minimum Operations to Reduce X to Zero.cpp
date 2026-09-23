class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot = accumulate(begin(nums), end(nums), 0), N = nums.size();
        int windowVal = tot-x;
        if (windowVal < 0) return -1;
        
        int res = -1, left = 0, curr = 0;

        for (int i=0; i<nums.size(); i++) {
            curr += nums[i];
            while (curr > windowVal) {
                curr -= nums[left];
                left++;
            }

            if (curr == windowVal) {
                res = max(res, i-left+1);
            }
        }

        return res == -1?-1:N-res;
    }
};