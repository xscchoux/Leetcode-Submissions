class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        int N = s.size();
        unordered_map<string, string> hmap;
        for (auto &k:knowledge) {
            string key = k[0], val = k[1];
            hmap[key] = val;
        }

        int idx = 0;
        while (idx < N) {
            if (s[idx] == '(') {
                int curr = idx + 1;
                string k;
                while (curr < N && s[curr] != ')') {
                    k.push_back(s[curr]);
                    curr += 1;
                }
                if (hmap.contains(k)) {
                    res += hmap[k];
                } else {
                    res.push_back('?');
                }
                idx = curr + 1;
            } else {
                res.push_back(s[idx]);
                idx++;
            }
        }

        return res;
    }
};