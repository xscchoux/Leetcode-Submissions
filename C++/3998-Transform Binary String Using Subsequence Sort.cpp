// Note that one only move '0' characters to the left and '1' characters to the right.
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int ones = count(begin(s), end(s), '1'), zeros = count(begin(s), end(s), '0');
        int N = s.size();

        vector<bool> res;
        for (auto &str:strs) {
            // actually we don't need strZero here...
            int questions = 0, strOne = 0, strZero = 0;
            for (char c:str) {
                if (c == '?') {
                    questions++;
                } else if (c == '1') {
                    strOne++;
                } else {
                    strZero++;
                }
            }

            int diffOne = ones - strOne;
            if (diffOne < 0 || diffOne > questions) {
                res.push_back(false);
                continue;
            }

            // replace '?' with '1' and '0'
            for (int i=str.size()-1; i>=0; i--) {
                if (str[i] == '?') {
                    if (diffOne > 0) {
                        str[i] = '1';
                        diffOne--;
                    } else {
                        str[i] = '0';
                    }
                }
            }

            // compare prefix ones
            int sOneCnt = 0, strOneCnt = 0;
            bool found = false;
            for (int i=0; i<N; i++) {
                if (s[i] == '1') {
                    sOneCnt++;
                }
                if (str[i] == '1') {
                    strOneCnt++;
                }
                if (strOneCnt > sOneCnt) {
                    res.push_back(false);
                    found = true;
                    break;
                }
            }
            if (!found) res.push_back(true);
        }

        return res;
    }
};