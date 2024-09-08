using LL = long long;
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int N = nums.size();
        int mx = nums[0];
        LL res = 0;
        for (int i=1; i<N; i++) {
            res += mx;
            if (nums[i] > mx) {
                mx = nums[i];
            }
        }
        return res;
    }
};