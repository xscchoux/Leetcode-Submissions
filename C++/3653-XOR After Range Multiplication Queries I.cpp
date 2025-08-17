class Solution {
public:
    int kMod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto &q:queries) {
            int left = q[0], right = q[1], k = q[2], v = q[3];

            while (left <= right) {
                nums[left] = ((long long)nums[left]*v)%kMod;
                left += k;
            }
        }

        int res = 0;
        for (int num:nums) {
            res ^= num;
        }

        return res;
    }
};