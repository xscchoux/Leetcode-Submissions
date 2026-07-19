class Solution {
public:
    string smallestSubsequence(string s) {
        int N = s.size();

        vector<int> last(26, -1);
        for (int i=0; i<s.size(); i++) {
            last[s[i]-'a'] = i;
        }

        vector<char> stk;
        unordered_set<char> used;

        for (int i=0; i<N; i++) {
            if (used.contains(s[i])) continue;
            while (!stk.empty() && stk.back() > s[i] && last[stk.back()-'a'] > i) {
                used.erase(stk.back());
                stk.pop_back();
            }
            stk.push_back(s[i]);
            used.insert(s[i]);
        }

        string res = "";
        for (char c:stk) {
            res += c;
        }

        return res;
    }
};