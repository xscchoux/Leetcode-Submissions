// backtracking
class Solution {
public:
    int N;
    bool dfs(string& pattern, vector<bool>& used, string& curr) {
        if (curr.size() == N+1) {
            return true;
        }

        for (int i=1; i<=9; i++) {
            if (curr.empty() || (((curr.back()-'0' < i && pattern[curr.size()-1] == 'I') || (curr.back()-'0' > i && pattern[curr.size()-1] == 'D')) && !used[i])) {
                curr.push_back(i+'0');
                used[i] = true;
                if (dfs(pattern, used, curr)) {
                    return true;
                }
                used[i] = false;
                curr.pop_back();
            }
        }
        return false;
    }

    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        this->N = pattern.size();
        string curr = "";
        dfs(pattern, used, curr);

        return curr;
    }
};

// tricky stack O(n) solution
class Solution {
public:
    string smallestNumber(string pattern) {
        int N = pattern.size();
        stack<int> stk;
        string res = "";

        for (int i=0; i<pattern.size(); i++) {
            if (pattern[i] == 'I') {
                res += to_string(i+1);
                while (!stk.empty()) {
                    res += to_string(stk.top());
                    stk.pop();
                }
            } else {
                stk.push(i+1);  // store the elements to be added to string reversely
            }
        }

        res += to_string(pattern.size() + 1);
        while (!stk.empty()) {
            res += to_string(stk.top());
            stk.pop();
        }

        return res;
    }
};