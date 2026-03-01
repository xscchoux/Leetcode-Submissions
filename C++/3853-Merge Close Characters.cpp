class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char, int> charPos;
        int merged = 0;
        string res = "";

        for (int i=0; i<s.size(); i++) {
            if (charPos.contains(s[i]) && (i - merged) - charPos[s[i]]<= k) {
                merged++;
            } else {
                res += s[i];
                charPos[s[i]] = i-merged;
            }
        }

        return res;
    }
};