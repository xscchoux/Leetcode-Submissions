class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int res = 0, cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == mx) {
                cnt++;
                res = max(cnt, res);
            } else {
                cnt = 0;
            }
        }

        return res;
    }
};