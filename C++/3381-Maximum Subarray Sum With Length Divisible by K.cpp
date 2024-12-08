using LL = long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        vector<LL> preVal(k, LLONG_MAX/2); // index%k, minimum value
        preVal[0] = 0;

        LL running = 0;
        LL res = LLONG_MIN/2;

        for (int i=0; i<N; i++) {
            running += nums[i];
            if (preVal[(i+1)%k] != LLONG_MAX/2) {
                res = max(res, running - preVal[(i+1)%k] );
            }
            preVal[(i+1)%k] = min(preVal[(i+1)%k], running);
        }

        return res;
    }
};