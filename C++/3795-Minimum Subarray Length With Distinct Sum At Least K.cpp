class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int left = 0, currSum = 0, N = nums.size(), res = N+1;

        for (int i=0; i<N; i++) {
            if (!cnt.contains(nums[i]) || cnt[nums[i]] == 0) {
                cnt[nums[i]] = 1;
                currSum += nums[i];
            } else {
                cnt[nums[i]]++;
            }

            while (left <= i && currSum >= k) {
                res = min(res, i-left+1);
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0) {
                    // cnt.erase(nums[left]);  using erase makes code slower
                    currSum -= nums[left];
                }
                left++;
            }
        }

        return (res == N+1)?-1:res;
    }
};