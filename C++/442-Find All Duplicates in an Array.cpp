class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int num:nums) {
            if (nums[abs(num)-1] < 0) {
                res.push_back(abs(num));
            } else {
                nums[abs(num)-1] *= -1;
            }
        }
        return res;
    }
};