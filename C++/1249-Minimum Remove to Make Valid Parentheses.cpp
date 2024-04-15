class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        int pairs = 0;

        // Pass 1: Remove all invalid ")"   
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                if (count == 0) s[i] = '#';
                else {
                    count--;
                    pairs++;
                }
            }
        }
        
        // Pass 2: Remove the rightmost(redundant) "("
        string res;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '#') continue;
            if (s[i] == '(') {
                pairs--;
                if (pairs < 0) continue;
            }
            res.push_back(s[i]);
        }

        return res;
    }
};