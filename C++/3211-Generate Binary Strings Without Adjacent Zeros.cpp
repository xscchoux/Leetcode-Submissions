class Solution {
public:
    int n;
    vector<string> allCases;
    void dfs(int idx, string& curr, bool prevIsZero) {
        if (idx == n) {
            allCases.push_back(curr);
            return;
        }
        curr.push_back('1');
        dfs(idx+1, curr, false);
        curr.pop_back();
        if (!prevIsZero) {
            curr.push_back('0');
            dfs(idx+1, curr, true);
            curr.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        this->n = n;
        string c = "";
        dfs(0, c, false);

        return allCases;
    }
};