class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, left = 0, N = nums.size(), curr = 0;
        vector<int> cnt(10001, 0);

        for (int i=0; i<N; i++) {
            curr += nums[i];
            cnt[nums[i]]++;
            while (cnt[nums[i]] > 1) {
                cnt[nums[left]]--;
                curr -= nums[left];
                left++;
            }
            res = max(res, curr);
        }

        return res;
    }
};