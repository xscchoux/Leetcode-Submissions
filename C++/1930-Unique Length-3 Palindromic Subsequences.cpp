class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> cnt(26);
        for (char c:s) cnt[c-'a']++;
        vector<int> pre(26);
        vector<vector<int>> visited(26, vector<int>(26, 0));
        int res = 0;

        for (char c:s) {
            cnt[c-'a']--;
            for (int i=0; i<26; i++) {
                if (pre[i] > 0 && cnt[i] > 0 && !visited[c-'a'][i]) {
                    visited[c-'a'][i] = 1;
                    res++;
                }
            }
            pre[c-'a']++;
        }

        return res;
    }
};