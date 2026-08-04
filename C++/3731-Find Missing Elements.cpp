class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int idx = 0;
        vector<int> res;
        for (int num = nums[0]; num<= nums.back(); num++) {
            if (num == nums[idx]) {
                idx++;
            } else {
                res.push_back(num);
            }
        }

        return res;
    }
};