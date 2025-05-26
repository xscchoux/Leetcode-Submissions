class Solution {
public:
    string resultingString(string s) {
        string res = "";

        for (char c:s) {
            if (!res.empty() && (abs(c - res.back()) == 1 || abs(c - res.back()) == 25)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};