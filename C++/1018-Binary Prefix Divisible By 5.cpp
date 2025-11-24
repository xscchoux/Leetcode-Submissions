class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0;
        vector<bool> res;
        for (int num:nums) {
            curr = (curr*2 + num)%5;
            res.push_back(curr == 0);
        }
        return res;
    }
};