class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int N = nums.size(), left = 0;
        long long res = 0, sum = 0;

        for (int i=0; i<N; i++) {
            sum += nums[i];
            while (sum*(i-left+1) >= k) {
                sum -= nums[left];
                left++;
            }
            res += i-left+1;
        }

        return res;
    }
};