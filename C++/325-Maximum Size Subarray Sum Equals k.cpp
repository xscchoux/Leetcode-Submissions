using LL = long long;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<LL, int> hmap;
        hmap[0] = -1;
        LL curr = 0;
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            curr += nums[i];
            if (hmap.contains(curr-k)) {
                res = max(res, i-hmap[curr-k]);
            }

            if (!hmap.contains(curr)) {
                hmap[curr] = i;
            }
        }

        return res;
    }
};