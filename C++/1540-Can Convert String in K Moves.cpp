class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        vector<int> cnt(26);
        int N = s.size();
        if (N != t.size()) return false;

        for (int i=0; i<N; i++) {
            cnt[(t[i]-s[i]+26)%26]++;
        }

        for (int i=1; i<26; i++) {
            if (cnt[i] == 0) continue;
            if (i + (cnt[i]-1)*26 > k) return false;
        }

        return true;
    }
};