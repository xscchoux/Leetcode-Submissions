// First AC
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int N = nums.size();

        // dp0[i]: value of the starting element for a subarray
        // dp1[i]: maximum sum of subarray 1 ending at index i
        // dp2[i]: maximum sum of subarray 1 and 2 ending at index i
        // dp3[i]: maximum sum of subarray 1 and 2 and 3 ending at index i
        vector<long long> dp0(N, 0), dp1(N, LLONG_MIN/2), dp2(N, LLONG_MIN/2), dp3(N, LLONG_MIN/2);
        for (int i=0; i<N; i++) {
            dp0[i] = nums[i];
        }

        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                dp1[i] = max(dp1[i-1] + nums[i], dp0[i-1] + nums[i]);
                dp3[i] = max(dp2[i-1] + nums[i], dp3[i-1] + nums[i]);
            } else if (nums[i] < nums[i-1]) {
                dp2[i] = max(dp2[i-1] + nums[i], dp1[i-1] + nums[i]);
            }
        }

        return *max_element(begin(dp3), end(dp3));
    }
};

// dp0 is not needed
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int N = nums.size();

        // dp1[i]: maximum sum of subarray 1 ending at index i
        // dp2[i]: maximum sum of subarray 1 and 2 ending at index i
        // dp3[i]: maximum sum of subarray 1 and 2 and 3 ending at index i
        vector<long long> dp1(N, LLONG_MIN/2), dp2(N, LLONG_MIN/2), dp3(N, LLONG_MIN/2);

        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                dp1[i] = max(dp1[i-1] + nums[i], (long long)nums[i-1] + nums[i]);
                dp3[i] = max(dp2[i-1] + nums[i], dp3[i-1] + nums[i]);
            } else if (nums[i] < nums[i-1]) {
                dp2[i] = max(dp2[i-1] + nums[i], dp1[i-1] + nums[i]);
            }
        }

        return *max_element(begin(dp3), end(dp3));
    }
};