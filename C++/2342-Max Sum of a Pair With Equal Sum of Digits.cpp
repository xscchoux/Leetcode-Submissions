class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int res = -1;

        for (int num:nums) {
            int tot = 0, tmp = num;
            while (tmp > 0) {
                tot += tmp%10;
                tmp /= 10;
            }

            if (hmap[tot] == 0) {
                hmap[tot] = num;
            } else {
                res = max(res, num+hmap[tot]);
                hmap[tot] = max(hmap[tot], num);
            }
        }

        return res;
    }
};