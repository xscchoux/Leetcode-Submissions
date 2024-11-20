class Solution {
public:
    int takeCharacters(string s, int k) {
        int N = s.size();
        int cnt[3];
        for (char c:s) cnt[c-'a']++;
        for (int i=0; i<3; i++) {
            if (cnt[i] < k) return -1;
        }

        int left = 0, res = N;

        int running[3];
        for (int i=0; i<N; i++) {
            running[s[i]-'a']++;
            while (cnt[s[i]-'a'] - running[s[i]-'a'] < k) {
                running[s[left++]-'a']--;
            }
            res = min(res, N-(i-left+1));
        }

        return res;
    }
};