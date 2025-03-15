class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cnt(26, 0);
        for (int i=0; i<s.size(); i++) {
            cnt[s[i]-'a']++;
        }
        int odd = 0;
        for (int i=0; i<26; i++) {
            if (cnt[i]%2) odd++;
            if (odd > 1) return false;
        }

        return true;
    }
};