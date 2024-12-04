class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx2 = 0;
        for (char c:str1) {
            if (c == str2[idx2] || ((c-'a'+1)%26 == str2[idx2]-'a')) {
                idx2++;
            }
            if (idx2 == str2.size()) return true;
        }
        return false;
    }
};