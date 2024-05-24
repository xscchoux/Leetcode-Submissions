class Solution {
    int res;
    int N;
    vector<int> cnt;
public:
    int dfs(int ind, vector<string>& words, vector<int>& score) {
        if (ind == N) return 0;
        // skip
        int ans = dfs(ind+1, words, score);
        // add
        vector<int> tmp(26, 0);
        bool canPut = true;
        for (char c:words[ind]) tmp[c-'a']++;
        for (int i=0; i<26; i++) {
            if (cnt[i] < tmp[i]) {
                canPut = false;
                break;
            }
        }
        if (canPut) {
            int curr = 0;
            for (int i=0; i<26; i++) {
                cnt[i] -= tmp[i];
                curr += tmp[i]*score[i];
            }
            ans = max(ans, curr + dfs(ind+1,  words, score));
            for (int i=0; i<26; i++) cnt[i] += tmp[i];
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        cnt = vector<int>(26, 0);
        res = 0;
        N = words.size();
        for (char l:letters) cnt[l-'a']++;
        return dfs(0, words, score);
    }
};