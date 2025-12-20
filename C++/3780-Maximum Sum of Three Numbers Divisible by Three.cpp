class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> one(3, 0), two(3, 0);
        int res = 0;
        
        for (int num:nums) {
            int mirrorRem = (3-num%3)%3;
            if (two[mirrorRem] > 0) {
                res = max(res, two[mirrorRem] + num);
            }

            for (int i=0; i<3; i++) {
                if (one[i] > 0) {
                    int counterpart = (num + one[i])%3;
                    two[counterpart] = max(two[counterpart], one[i] + num);
                }
            }
            
            one[num%3] = max(one[num%3], num);
        }

        return res;
    }
};