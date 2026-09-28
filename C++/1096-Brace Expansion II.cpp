class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int N = expression.size();
        vector<char> op;   // store operations: '{', '+', '*'
        vector<set<string>> stk;  // store the sets of strings, ex: {a}, {b}, {cd}, ....

        // merge elements in stk according to op
        auto operation = [&]() {
            int left = stk.size()-2, right = stk.size()-1;
            if (op.back() == '+') {
                stk[left].merge(stk[right]);
            } else {
                set<string> tmp;
                for (string lval: stk[left]) {
                    for (string rval: stk[right]) {
                        tmp.insert(lval + rval);
                    }
                }
                stk[left] = move(tmp);
            }

            stk.pop_back();
            op.pop_back();
        };


        for (int i=0; i<N; i++) {
            if (expression[i] == '{') {
                if (i > 0 && (expression[i-1] == '}' || isalpha(expression[i-1])) ) {
                    op.push_back('*');
                }
                op.push_back('{');
            } else if (expression[i] == '}') {
                while (op.size() && op.back() != '{') {
                    operation();
                }
                op.pop_back();  // pop '{'
            } else if (expression[i] == ',') {
                while (op.size() && op.back() == '*') {
                    operation();
                }
                op.push_back('+');
            } else {
                if (i > 0 && (expression[i-1] == '}' || isalpha(expression[i-1]))) {
                    op.push_back('*');
                }
                stk.push_back({string(1, expression[i])});
            }
        }

        while (op.size()) {
            operation();
        }

        return vector<string>(begin(stk.back()), end(stk.back()));
    }
};