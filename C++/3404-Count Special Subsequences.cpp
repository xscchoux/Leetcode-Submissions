// O(m^2 * log(1000))
// https://leetcode.com/problems/count-special-subsequences/solutions/6199807/gcd-superfast/
class Solution {
public:
    int cnt[1001][1001] = {};
    long long numberOfSubsequences(vector<int>& nums) {
        int N = nums.size();
        long long res = 0;

        // q/p = r/s
        for (int q=N-5; q>=2; q--) {
            for (int s=q+4, r=q+2; s<N; s++) {
                int gcdVal = gcd(nums[r], nums[s]);
                cnt[nums[r]/gcdVal][nums[s]/gcdVal]++;
            }

            for (int p=q-2; p>=0; p--) {
                int gcdVal = gcd(nums[p], nums[q]);
                res += cnt[nums[q]/gcdVal][nums[p]/gcdVal];
            }
        }

        return res;
    }
};