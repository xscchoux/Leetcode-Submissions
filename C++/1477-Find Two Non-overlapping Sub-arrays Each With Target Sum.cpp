class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int N = arr.size();
        unordered_map<int, int> pos;
        pos[0] = -1;
        int curr = 0, res = N+1, minLength = N+1;
        vector<int> dp(N, -1);  // dp[i] : minimum-length subarray within arr[0:i+1] with target sum

        for (int i=0; i<N; i++) {
            curr += arr[i];
            if (pos.contains(curr-target)) {
                int j = pos[curr-target];
                int currLength = i-j;
                if (j != -1 && dp[j] != -1) {
                    res = min(res, i-j + dp[j]);
                }
                minLength = min(minLength, currLength);
            }

            dp[i] = minLength;
            pos[curr] = i;
        }

        return res==(N+1)?-1:res;
    }
};