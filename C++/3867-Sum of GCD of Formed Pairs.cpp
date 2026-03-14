class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0, N = nums.size();
        vector<int> prefixGcd(N, 0);
        for (int i=0; i<N; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = __gcd(nums[i], mx);
        }

        sort(begin(prefixGcd), end(prefixGcd));

        int left = 0, right = N-1;
        long long res = 0;
        while (left < right) {
            res += __gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return res;
    }
};