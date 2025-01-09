class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string& word:words) {
            if (word.compare(0, pref.size(), pref) == 0) res++;
        }
        return res;
    }
};