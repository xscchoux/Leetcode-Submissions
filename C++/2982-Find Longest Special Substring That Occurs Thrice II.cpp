// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/discuss/4481019/c%2B%2B-or-java-or-python-or-Easiest-solution-~-O(N)
class Solution {
public:
    int maximumLength(string s) {
        int N = s.size();
        vector<vector<int>> dp(26, vector<int>(N+1, 0));
        int count = 1, res = -1, pre = s[0];
        dp[s[0]-'a'][count] = 1;

        for (int i=1; i<N; i++){
            if (s[i] == pre){
                count += 1;
                dp[s[i]-'a'][count]++;
            } else {
                count = 1;
                dp[s[i]-'a'][count]++;
            }
            pre = s[i];
        }
        
        for (int c=0; c<26; c++) {
            int preSum = 0;
            for (int n=N; n>=1; n--){
                preSum += dp[c][n];
                if (preSum >= 3) {
                    res = max(res, n);
                    break;
                }
            }
        }
        return res;
    };
};