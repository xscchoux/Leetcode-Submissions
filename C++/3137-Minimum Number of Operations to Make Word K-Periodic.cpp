class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> hmap;
        const int N = word.size();
        int maxCnt = 0;

        for (int i=0; i<N; i+=k) {
            maxCnt = max(maxCnt, ++hmap[word.substr(i, k)]);
        }

        return N/k - maxCnt;
    }
};