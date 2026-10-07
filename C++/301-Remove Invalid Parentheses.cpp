class Solution {
public:
    int left = 0, right = 0, N, minRemove;
    unordered_set<string> res;
    void dfs(int idx, int l, int r, string &curr, string& s) {
        if (idx == N) {
            int removed = right + left - l - r;
            if (l == r) {
                if (removed > minRemove) {
                    return;
                } else if (removed == minRemove) {
                    res.insert(curr);
                } else {
                    res.clear();
                    minRemove = removed;
                    res.insert(curr);
                }
            }
            return;
        }

        // skip
        if (s[idx] == '(' || s[idx] == ')') {
            dfs(idx+1, l, r, curr, s);
        }


        if (s[idx] == '(') {
            curr.push_back(s[idx]);
            dfs(idx+1, l+1, r, curr, s);
            curr.pop_back();
        } else if (s[idx] == ')') {
            if (l >= r+1) {
                curr.push_back(s[idx]);
                dfs(idx+1, l, r+1, curr, s);
                curr.pop_back();
            }
        } else {
            curr.push_back(s[idx]);
            dfs(idx+1, l, r, curr, s);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        this->N = s.size();
        this->minRemove = N;
        for (char c:s) {
            if (c == '(') left++;
            else if (c == ')') right++;
        }

        string tmp = "";
        dfs(0, 0, 0, tmp, s);

        return vector<string>(res.begin(), res.end());
    }
};