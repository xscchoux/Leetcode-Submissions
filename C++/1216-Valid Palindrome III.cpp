int dp[1000][1000];
class Solution {
public:
    int isOK(string& s, int left, int right) {
        if (left >= right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        if (s[left] == s[right]) return dp[left][right] = isOK(s, left+1, right-1);
        return dp[left][right] = 1 + min(isOK(s, left+1, right), isOK(s, left, right-1));
    }
    
    bool isValidPalindrome(string s, int k) {
        int N = s.size();
        memset(dp, -1, sizeof(dp));
        int ans = isOK(s, 0, N-1);
        return isOK(s, 0, N-1) <= k;
    }
};