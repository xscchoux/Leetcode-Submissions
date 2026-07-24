class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int N = s.size();
        vector<bool> bold(N, false);

        for (auto &word:words) {
            int sz = word.size();
            for (int start=0; start+sz-1<N; start++) {
                int idx = 0;
                bool found = true;
                for (int j=0; j<sz; j++) {
                    if (s[start+j] != word[idx++]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    for (int k = start; k<start+sz; k++) {
                        bold[k] = true;
                    }
                }
            }
        }

        string res = "";
        bool isBold = false;
        for (int i=0; i<N; i++) {
            if (bold[i] && !isBold) {
                res += "<b>";
                isBold = true;
            }
            if (!bold[i] && isBold) {
                res += "</b>";
                isBold = false;
            }
            res += s[i];
        }

        if (isBold) {
            res += "</b>";
        }

        return res;
    }
};