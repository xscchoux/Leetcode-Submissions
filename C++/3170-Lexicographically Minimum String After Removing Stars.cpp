class Solution {
public:
    string clearStars(string s) {
        vector<int> arr;
        int N = s.size();
        unordered_set<int> deleted;
        vector<vector<int>> idx(26);

        for (int i=0; i<N; i++) {
            if (s[i] == '*') {
                for (int j=0; j<26; j++) {
                    if (!idx[j].empty()) {
                        deleted.insert(idx[j].back());
                        idx[j].pop_back();
                        break;
                    }
                }
            } else {
                idx[s[i]-'a'].push_back(i);
            }
        }

        string res = "";
        for (int i=0; i<N; i++) {
            if (s[i] == '*' || deleted.contains(i)) continue;
            res += s[i];
        }

        return res;
    }
};