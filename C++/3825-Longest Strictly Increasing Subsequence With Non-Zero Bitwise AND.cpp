class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        for (int b=0; b<=30; b++) {
            vector<int> arr;
            for (int num:nums) {
                if (num&(1<<b)) {
                    arr.push_back(num);
                }
            }

            vector<int> tmp;
            for (int num:arr) {
                if (tmp.empty() || num > tmp.back()) {
                    tmp.push_back(num);
                } else {
                    *lower_bound(begin(tmp), end(tmp), num) = num;
                }
            }
            res = max(res, (int)tmp.size());
        }

        return res;

    }
};