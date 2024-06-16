using LL = long long;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        LL next_missing = 1;
        int ind = 0, N = nums.size();
        int res = 0;

        while (next_missing <= n) {
            if (ind < N && next_missing >= nums[ind]) {
                next_missing += nums[ind];
                ind++;
            } else {
                res++;
                next_missing = next_missing*2;
            }
        }

        return res;
    }
};