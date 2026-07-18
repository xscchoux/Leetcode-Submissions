using LL = long long;
class Solution {
public:
    int N;
    LL operated(int num, int k, int op) {
        if (op == 0) {  // multiply
            return 1LL*num*k;
        } else {
            if (num >= 0) {
                return 1LL*(num/k);
            } else {
                return 1LL*(-((-num)/k));
            }
        }
    }
    long long getSum(vector<int>& nums, int k, int op) {
        // dp0: haven't multiply or divide
        // dp1: is divided or multiplied by k
        // dp2: finished dividing or multiplying, now add nums[i]
        vector<LL> dp0(N, LLONG_MIN/2), dp1(N, LLONG_MIN/2), dp2(N, LLONG_MIN/2);

        dp0[0] = nums[0];
        dp1[0] = operated(nums[0], k, op);
        // dp2[0] = LLONG_MIN/2;
        
        long long mx = max(dp0[0], dp1[0]);
        
        for (int i=1; i<N; i++) {
            LL val = operated(nums[i], k, op);
            dp0[i] = max(1LL*nums[i], dp0[i-1] + nums[i]);
            dp1[i] = max({val, dp0[i-1] + val, dp1[i-1] + val});
            dp2[i] = max({dp1[i-1] + nums[i], dp2[i-1] + nums[i]});
            mx = max({mx, dp0[i], dp1[i], dp2[i]});
        }

        return mx;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        this->N = nums.size();

        return max(getSum(nums, k, 0), getSum(nums, k, 1));
    }
};