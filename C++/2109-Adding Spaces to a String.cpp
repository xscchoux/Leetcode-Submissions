class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newS;
        // Pre-allocate space for efficiency
        newS.reserve(s.size() + spaces.size());

        int j = 0;
        for (int i=0; i<s.size(); i++) {
            if (j<spaces.size() && i == spaces[j]) {
                newS += " ";
                j++;
            }
            newS += s[i];
        }
        return newS;
    }
};