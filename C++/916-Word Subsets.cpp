class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> word2Cnt(26);
        for (string &word:words2) {
            vector<int> tmp(26);
            for (char w:word) {
                tmp[w-'a']++;
            }
            for (int i=0; i<26; i++) {
                word2Cnt[i] = max(word2Cnt[i], tmp[i]);
            }
        }

        vector<string> res;
        for (string &word:words1) {
            vector<int> tmp(26);
            for (char w:word) {
                tmp[w-'a']++;
            }
            bool isOK = true;
            for (int i=0; i<26; i++) {
                if (tmp[i] < word2Cnt[i]) {
                    isOK = false;
                    break;
                }
            }
            if (isOK) {
                res.push_back(word);
            }
        }

        return res;
    }
};