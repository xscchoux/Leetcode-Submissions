class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> cnt;
        int maxVal = 0;
        for (int num:nums) {
            cnt[num]++;
            maxVal = max(maxVal, num);
        }

        int res = 0;
        for (int i=nums[0]; i<=nums.back(); i++) {
            int leftIdx = lower_bound(nums.begin(), nums.end(), i-k) - nums.begin();
            int rightIdx = upper_bound(nums.begin(), nums.end(), i+k) - nums.begin();
            res = max(res, cnt[i] + min(numOperations, rightIdx-leftIdx-cnt[i]));
        }

        return res;
    }
};