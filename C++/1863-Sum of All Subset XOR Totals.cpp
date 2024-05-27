class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        vector<int> prev;
        prev.push_back(0);

        for (int num:nums) {
            vector<int> temp;
            for (int preVal:prev) {
                res += preVal^num;
                temp.push_back(preVal^num);
            }
            for (int t:temp) {
                prev.push_back(t);
            }
        }

        return res;
    }
};