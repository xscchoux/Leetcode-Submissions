class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for (string& s: queries) {
            for (auto& d:dictionary) {
                int cnt = 0;
                for (int i=0; i<s.size(); i++) {
                    if (d[i] != s[i]) {
                        cnt++;
                        if (cnt > 2) {
                            break;
                        }
                    }
                }
                if (cnt <= 2) {
                    res.push_back(s);
                    break;
                }
            }
        }

        return res;
    }
};