class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);
        int res = 0;

        for (char c:s) {
            cnt[c-'a']++;
        }

        for (int i=0; i<26; i++) {
            if (cnt[i]%2) res+=1;
            else if (cnt[i]) res+=2;
        }
        return res;
    }
};