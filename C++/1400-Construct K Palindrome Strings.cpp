class Solution {
public:
    bool canConstruct(string s, int k) {
        int N = s.size();
        if (k > N) return false;
        vector<int> cnt(26, 0);

        for (char c:s) {
            cnt[c-'a']++;
        }

        int single = 0;
        for (int i=0; i<26; i++) {
            if (cnt[i]%2 == 1) single++;
        }
        if (single > k) return false;

        return true;
    }
};