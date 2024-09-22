class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(begin(bannedWords), end(bannedWords));
        int cnt = 0;
        for (auto &m:message) {
            if (banned.contains(m)) {
                if (++cnt == 2) return true;
            }
        }

        return false;
    }
};