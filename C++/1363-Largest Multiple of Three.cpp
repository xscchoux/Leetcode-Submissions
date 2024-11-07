// https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/1363.Largest-Multiple-of-Three/1363.Largest-Multiple-of-Three_v2.cpp
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int N = digits.size();
        vector<vector<int>> dp(N+1, vector<int>(3, INT_MIN));  // maximum length of the state dp[index][remainder]
        vector<vector<int>> prev(N+1, vector<int>(3, -1));  // previous remainder
        vector<vector<bool>> picked(N+1, vector<bool>(3, false));
        dp[0][0] = 0;

        sort(begin(digits), end(digits), greater<>());

        for (int i=1; i<=N; i++) {
            for (int j=0; j<3; j++) { // remainder
                int prevJ = (3+j-digits[i-1]%3)%3;
                if (dp[i-1][j] >= 1 + dp[i-1][prevJ]) {
                    dp[i][j] = dp[i-1][j];
                    prev[i][j] = j;
                    picked[i][j] = false;
                } else {
                    dp[i][j] = 1 + dp[i-1][prevJ];
                    prev[i][j] = prevJ;
                    picked[i][j] = true;
                }
            }
        }

        int mod = 0;
        string res;
        for (int i=N-1; i>=0; i--) {
            if (picked[i+1][mod]) {
                res += (digits[i] + '0');
                mod = (3+mod-digits[i]%3)%3;
            }
        }

        reverse(begin(res), end(res));
        if (res[0] == '0') return "0";

        return res;
    }
};