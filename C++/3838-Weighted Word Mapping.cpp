class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";

        for (auto &w:words) {
            int tot = 0;
            for (int i=0; i<w.size(); i++) {
                tot += weights[w[i]-'a'];
            }
            tot %= 26;
            res += (26-tot-1) +'a';
        }

        return res;
    }
};