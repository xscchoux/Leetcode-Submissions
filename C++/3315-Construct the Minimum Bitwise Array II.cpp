// Toggle the leftmost bit in the rightmost group of consecutive 1s
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int num:nums) {
            if (num == 2) res.push_back(-1);
            else {
                int tmp = num;
                int cntOne = 0;
                while (tmp%2 == 1) {
                    cntOne++;
                    tmp /= 2;
                }
                cntOne--;
                int mask = (1<<cntOne);
                res.push_back(num^mask);
            }
        }
        return res;
    }
};