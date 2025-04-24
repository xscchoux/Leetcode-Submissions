class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int tot = s.size();

        int left = 0, res = 0;
        unordered_map<int, int> cnt;
        for (int i=0; i<nums.size(); i++) {
            cnt[nums[i]]++;
            while (cnt.size() == tot && cnt[nums[left]] > 1) {
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0) {
                    cnt.erase(nums[left]);
                }
                left++;
            }

            if (cnt.size() == tot) res += left+1;
        }

        return res;
    }
};