// https://www.youtube.com/watch?v=h6R2NEdwlQ8
using LL = long long;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int kMod = 1e9+7;
        int mx = *max_element(begin(nums), end(nums));
        cost2 = min(2*cost1, cost2);
        sort(nums.begin(), nums.end());
        LL tot = accumulate(begin(nums), end(nums), 0LL);
        LL res = LLONG_MAX;

        for (LL limit=mx; limit<=2*mx; limit++) {
            LL remain = limit*N - tot;    // total increase needed
            LL remain0 = limit-nums[0], otherRemain = remain-remain0; // remain0: increase needed for nums[0]
            LL curr = 0;
            if (remain0 > otherRemain) {
                curr = otherRemain*cost2 + (remain0-otherRemain)*cost1;
            } else {
                curr = (remain/2)*cost2 + (remain%2?cost1:0);
            }
            res = min(res, curr);
        }

        return res%kMod;
    }
};