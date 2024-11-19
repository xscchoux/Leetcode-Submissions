class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        long long res = 0, tot = 0;
        for (int i=0; i<k; i++) {
            cnt[nums[i]]++;
            tot += nums[i];
        }

        if (cnt.size() == k) res = tot;

        for (int i=k; i<nums.size(); i++) {
            tot += nums[i]-nums[i-k];
            cnt[nums[i]]++;
            if (--cnt[nums[i-k]] == 0) cnt.erase(nums[i-k]);
            if (cnt.size() == k) {
                res = max(res, tot);
            }
        }
        return res;
    }
};