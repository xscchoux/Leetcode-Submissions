class Solution {
public:
    string processStr(string s) {
        string curr = "";

        for (char c:s) {
            if (c == '#') {
                curr.append(curr);
            } else if (c == '*') {
                if (!curr.empty()) {
                    curr.pop_back();
                }
            } else if (c == '%') {
                reverse(begin(curr), end(curr));
            } else {
                curr.push_back(c);
            }
        }

        return curr;
    }
};