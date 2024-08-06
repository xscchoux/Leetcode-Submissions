class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char w:word) cnt[w-'a']++;
        sort(cnt.begin(), cnt.end(), greater<>());

        int res = 0;
        for (int i=0; i<26; i++) {
            res += cnt[i]*(1+i/8);
        }

        return res;
    }
};