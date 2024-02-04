class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        string prefix = word.substr(0, k);
        int N = word.size();
        for (int i=k; i<N; i+=k) {
            string substring = word.substr(i);
            bool isSub = true;
            for (int j=0; j<substring.size(); j++) {
                if (word[j] != substring[j]) {
                    isSub = false;
                    break;
                }
            }
            if (isSub) return i/k;
        }
        
        return ceil(N/(float)k);
    }
};