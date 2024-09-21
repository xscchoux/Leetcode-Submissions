class Solution {
public:
    void buildLPS(string& s, vector<int>& LPS) {
        int i=1, j=0;
        while (i<s.size()) {
            if (s[i] == s[j]) {
                j++;
                LPS[i] = j;
                i++;
            } else { // s[i] != s[j]
                if (j == 0) {
                    i++;
                } else {
                    j = LPS[j-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string reversed = string(s.rbegin(), s.rend());
        string newS = s + '#' + reversed;
        int N = newS.size();
        vector<int> LPS(N, 0);
        buildLPS(newS, LPS);

        int overlapped = LPS[N-1];

        return reversed.substr(0, s.size()-overlapped) + s;
    }
};