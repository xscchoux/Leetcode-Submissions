using LL = long long;
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        LL res = 0;
        int median = N/2;
        
        for (int i=0; i<N; i++) {
            if (i == median) {
                res += abs(nums[i] - k);
            } else if (i > median) {
                res += max(0, k-nums[i]);
            } else {
                res += max(0, nums[i]-k);
            }
        }
        
        return res;
    }
};