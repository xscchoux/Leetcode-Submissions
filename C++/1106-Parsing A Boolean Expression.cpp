class Solution {
public:
    pair<bool, int> dfs(int i, string& expression, char operation) {
        int idx = i;
        vector<bool> arr;
        pair<bool, int> boolRes;
        while (expression[idx] != ')') {
            if (expression[idx] == 'f') {
                arr.push_back(false);
                idx++;
            } else if (expression[idx] == 't') {
                arr.push_back(true);
                idx++;
            } else if (expression[idx] == '&') {
                boolRes = dfs(idx+2, expression, '&');
                arr.push_back(boolRes.first);
                idx = boolRes.second;
            } else if (expression[idx] == '|') {
                boolRes = dfs(idx+2, expression, '|');
                arr.push_back(boolRes.first);
                idx = boolRes.second;
            } else if (expression[idx] == '!') {
                boolRes = dfs(idx+2, expression, '!');
                arr.push_back(boolRes.first);
                idx = boolRes.second;
            } else {
                idx++;
            }
        }
        bool res = arr[0];
        if (operation=='&') {
            for (int i=1; i<arr.size(); i++) res &= arr[i];
        } else if (operation=='|') {
            for (int i=1; i<arr.size(); i++) res |= arr[i];        
        } else {  // operation == !
            res = !res;
        }
        return {res, idx+1};
    }
    bool parseBoolExpr(string expression) {
        int idx = 0, N = expression.size();
        pair<bool, int> boolRes;
        while (idx < N) {
            if (expression[idx] == '&') {
                boolRes = dfs(idx+2, expression, '&');
                return boolRes.first;
            } else if (expression[idx] == '|') {
                boolRes = dfs(idx+2, expression, '|');
                return boolRes.first;
            } else if (expression[idx] == '!') {
                boolRes = dfs(idx+2, expression, '!');
                return boolRes.first;
            } else if (expression[idx] == 't') {
                return true;
            } else if (expression[idx] == 'f') {
                return false;
            }
        }
        return true;
    }
};




// hard and clever stack solution
class Solution {
public:
    bool parseBoolExpr(string expression) {
        if (expression[0] == 't') return true;
        if (expression[0] == 'f') return false;
        stack<char> stk;
        for (char c:expression) {
            if (c == ',' || c == '(') continue;
            if (c != ')') stk.push(c);
            else {  // when c == ')'
                bool hasTrue = false, hasFalse = false;
                while (stk.top() != '!' && stk.top() != '&' && stk.top() != '|') {
                    if (stk.top() == 't') hasTrue = true;
                    if (stk.top() == 'f') hasFalse = true;
                    stk.pop();
                }

                char op = stk.top();
                stk.pop();
                if (op == '&') {
                    stk.push(hasFalse?'f':'t');
                } else if (op == '|') {
                    stk.push(hasTrue?'t':'f');
                } else {  // op == '!'
                    stk.push(hasTrue?'f':'t');
                }
            }
        }
        return stk.top() == 't';
    }
};