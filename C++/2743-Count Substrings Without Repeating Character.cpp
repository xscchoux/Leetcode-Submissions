class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int left = 0, N = s.size(), res = 0;
        vector<int> cnt(26, 0);

        for (int i=0; i<N; i++) {
            cnt[s[i]-'a']++;
            while (left < i && cnt[s[i]-'a'] > 1) {
                cnt[s[left]-'a']--;
                left++;
            }
            res += i-left+1;
        }
        return res;
    }
};