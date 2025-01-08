class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int N = words.size();
        int res = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (words[j].compare(0, words[i].size(), words[i]) == 0 && words[j].compare(words[j].size()-words[i].size(), words[j].size(), words[i]) == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};