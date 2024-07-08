class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        string s1, s2;

        for (int i=0; i<start.size(); i++) {
            if (start[i] != 'X') s1 += start[i];
        }

        for (int i=0; i<end.size(); i++) {
            if (end[i] != 'X') s2 += end[i];
        }

        if (s1.size() != s2.size() || s1 != s2) return false;
        
        // L only moves left and R only moves right
        int i = 0, j = 0;
        for (int i=0; i<start.size(); i++) {
            if (start[i] == 'X') continue;
            while (j < start.size() && end[j] == 'X') {
                j++;
            }
            if ( (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            else {
                j++;
            }
        }
        return true;
    }
};