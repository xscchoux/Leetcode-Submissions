// build the final string from left to right while keeping the number of removed char
class Solution {
public:
    string mergeCharacters(string s, int k) {
        int N = s.size();
        int removed = 0;
        unordered_map<char, int> lastPos;
        string res = "";

        for (int i=0; i<N; i++) {
            if (lastPos.contains(s[i]) && i - removed - lastPos[s[i]] <= k) {
                removed++;
                continue;
            }
            lastPos[s[i]] = i - removed;  // the remaining characters are reindexed
            res.push_back(s[i]);
        }

        return res;
    }
};