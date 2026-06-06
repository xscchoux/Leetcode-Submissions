class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long res = 0;
        int N = s.size();

        // For consecutive blocks of '1's from index l to r, find sum(nums[l-1]....nums[r])- min(nums[l-1...r])
        // long long tot = 0;
        int idx = 0;
        while (idx < N) {
            if (s[idx] == '1') {
                long long tot = 0;
                int left = idx, mn = INT_MAX;
                while (idx < N && s[idx] == '1') {
                    tot += nums[idx];
                    mn = min(mn, nums[idx]);
                    idx++;
                }

                int right = idx-1;

                if (left > 0) {
                    tot += nums[left-1];
                    mn = min(mn, nums[left-1]);
                } else {
                    mn = 0;
                }

                res += tot -mn;
            }
            idx++;
        }

        return res;
    }
};