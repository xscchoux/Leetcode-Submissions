class Solution {
public:
    int longestCommonPrefix(string s, string t) {
        int Ns = s.size(), Nt = t.size();
        int idx1 = 0, idx2 = 0;
        bool removed = false;
        while (idx1 < Ns && idx2 < Nt) {
            if (s[idx1] == t[idx2]) {
                idx1++;
                idx2++;
            } else if (!removed){
                idx1++;
                removed = true;
            } else {
                break;
            }
        }

        return idx2;
    }
};