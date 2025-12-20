class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num:nums) cnt[num]++;

        int N = nums.size(), op = 0;

        for (int i=0; i<N; i++) {
            if (i%3 == 0) {
                if (N-i == cnt.size()) {
                    return op;
                }
                op++;
            }
            cnt[nums[i]]--;
            if (cnt[nums[i]] == 0) {
                cnt.erase(nums[i]);
            }
        }
        return op;
    }
};