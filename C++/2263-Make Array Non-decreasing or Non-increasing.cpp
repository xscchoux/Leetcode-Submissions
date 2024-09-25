class Solution {
public:
    int cal(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N+1, vector<int>(1001, 0));
        for (int i=1; i<=N; i++) {
            int minValue = INT_MAX;
            for (int j=0; j<=1000; j++) {
                if (dp[i-1][j] < minValue) {
                    minValue = dp[i-1][j];
                }
                dp[i][j] = minValue + abs(nums[i-1]-j);
            }
        }
        return *min_element(begin(dp[N]), end(dp[N]));
    }
    int convertArray(vector<int>& nums) {
        // dp[i][j]: operations to make nums[0:i+1] increasing and end with number j
        vector<int> reversed = nums;
        reverse(reversed.begin(), reversed.end());
        return min({cal(nums), cal(reversed)});
    }
};


// https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/solutions/2010254/DP-Heap-detailed-explanation/
// Priority queue solution, really hard
class Solution {
public:
    int cal (vector<int>& nums) {
        priority_queue<int, vector<int>> pq;
        int res = 0;

        for (int num:nums) {
            if (!pq.empty() && num < pq.top()) {
                int diff = pq.top() - num;
                res += diff;
                pq.pop();
                pq.push(num);
            }
            pq.push(num);
        }
        return res;
    }
    int convertArray(vector<int>& nums) {
        auto reversed = vector<int>(nums.rbegin(), nums.rend());
        return min(cal(nums), cal(reversed));
    }
};