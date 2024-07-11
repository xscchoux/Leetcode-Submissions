// My lengthy solution
class Solution {
public:
    int N;
    pair<int, string> dfs(int ind, string& s) {
        string curr = "";
        int nxtInd = N-1;
        for (int i = ind; i<N; i++) {
            if (s[i] == ')') {
                nxtInd = i;
                break;
            }
            if (s[i] == '(') {
                auto [nxt, c] = dfs(i+1, s);
                curr += c;
                nxtInd = nxt+1;
                i = nxt;
            }
            else curr += s[i];
        }
        reverse(curr.begin(), curr.end());
        return {nxtInd, curr};
    }
    string reverseParentheses(string s) {
        this->N = s.size();
        string res = "";
        int nxtInd = N-1;
        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                auto [nxtInd, c] = dfs(i+1, s);
                res += c;
                i = nxtInd;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};


// Wormhole Teleportation technique
class Solution {
public:
    string reverseParentheses(string s) {
        int N = s.size();
        vector<int> pair(N);
        stack<int> stk;
        string res = "";

        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int openIdx = stk.top();
                stk.pop();
                pair[i] = openIdx;
                pair[openIdx] = i;
            }
        }

        for (int i=0, direction=1; i<N; i+=direction) {
            if ( (s[i] == ')') || (s[i] == '(')) {
                i = pair[i];
                direction = -direction;
            } else {
                res += s[i];
            }
        }

        return res;
    }
};