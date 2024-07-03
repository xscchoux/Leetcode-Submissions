// O(n^2)
// class Solution {
// public:
//     int maxScore(vector<int>& nums) {
//         int N = nums.size();
//         vector<int> dp(N, 0);

//         for (int i=1; i<N; i++) {
//             for (int j=0; j<i; j++) {
//                 dp[i] = max(dp[i], dp[j] + (i-j)*nums[i]);
//             }
//         }

//         return dp[N-1];
//     }
// };

// O(n) solution
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int res = 0, N = nums.size(), mx = 0;
        for (int i=N-1; i>=1; i--) {
            mx = max(nums[i], mx);
            res += mx;
        }

        return res;
    }
};