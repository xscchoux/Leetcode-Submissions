class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hmap;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        while (ss1 >> word) {
            hmap[word]++;
        }

        while (ss2 >> word) {
            hmap[word]++;
        }        

        vector<string> res;

        for (auto &[k, v]:hmap) {
            if (v == 1) {
                res.push_back(k);
            }
        }

        return res;
    }
};