class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> hmap;
        int res = -1;
        for (int num:nums) {
            int half = sqrt(num);
            if (half*half == num && hmap.contains(half)) {
                hmap[num] = hmap[half]+1;
                res = max(res, hmap[num]);
            } else {
                hmap[num] = 1;
            }
        }

        return res;
    }
};