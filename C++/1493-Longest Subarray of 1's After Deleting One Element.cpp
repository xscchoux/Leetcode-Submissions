class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, curr = 0, left = 0, res = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 1) {
                curr++;
            } else {
                cnt++;
            }

            while (i>left && cnt >= 2) {
                if (nums[left] == 0) {
                    cnt--;
                } else {
                    curr--;
                }
                left++;
            }

            res = max(res, cnt==0?curr-1:curr);
        }

        return res;
    }
};