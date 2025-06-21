class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26, 0);
        int N = word.size();
        int res = INT_MAX;
        for (char c:word) {
            cnt[c-'a']++;
        }

        for (int i=0; i<26; i++) {
            if (cnt[i] == 0) continue;
            int currCount = 0;
            for (int j=0; j<26; j++) {
                if (cnt[j] == 0) continue;
                if (cnt[j] >= cnt[i] && cnt[j] <= cnt[i] + k) {
                    currCount += cnt[j];
                } else if (cnt[j] > cnt[i] + k) {
                    currCount += cnt[i] + k;
                }
            }
            res = min(res, N - currCount);
        }
        
        return res;
    }
};