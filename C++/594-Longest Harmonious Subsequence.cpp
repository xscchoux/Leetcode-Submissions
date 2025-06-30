class Solution {
public:
    int findLHS(vector<int>& nums) {
        int N = nums.size(), res = 0;
        unordered_map<int, int> cnt;
        for (int num:nums) {
            cnt[num]++;
        }

        // This is wrong:

        // for (auto &[k, v]:cnt) {
        //     if (cnt[k] > 0 && cnt[k+1] > 0) {
        //         res = max(res, cnt[k] + cnt[k+1]);
        //     }
        // }

        // Accessing cnt[k+1] using operator[] will insert a new key with value 0 if it doesn't exist.
        // This modifies the map cnt while you're iterating over it, which is undefined behavior.

        for (auto &[k, v]:cnt) {
            if (cnt.count(k+1)) {
                res = max(res, v + cnt[k+1]);
            }
        }

        return res;
    }
};