using LL = long long;
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        LL res = 0, N = nums.size();
        int inc = 0, dec = 0;
        for (int i=0; i<N; i++) {
            int diff = target[i] - nums[i];
            if (diff > 0) {
                if (diff > inc) {
                    res += diff - inc;
                }
                inc = diff;
                dec = 0;
            } else if (diff < 0) {
                if (diff < dec) {
                    res += dec - diff;
                }
                dec = diff;
                inc = 0;
            } else {
                dec = inc = 0;
            }
        }

        return res;
    }
};