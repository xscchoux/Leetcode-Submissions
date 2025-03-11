class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.size(), left = 0, res = 0;
        vector<int> cnt(3, 0);

        for (int i=0; i<N; i++) {
            cnt[s[i]-'a']++;
            while (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1) {
                res += N-i;
                cnt[s[left++]-'a']--;
            }
        }

        return res;
    }
};