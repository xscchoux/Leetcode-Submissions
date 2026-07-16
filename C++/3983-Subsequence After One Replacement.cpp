class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int Ns = s.size(), Nt = t.size();
        if (Ns == 1) return true;
        vector<int> earliestMatch(Ns, Nt+1), latestMatch(Ns, -1);

        int sIdx = 0;
        for (int i=0; i<t.size(); i++) {
            if (s[sIdx] == t[i]) {
                earliestMatch[sIdx] = i;
                sIdx++;
            }
            if (sIdx == s.size()) break;
        }


        sIdx = Ns-1;
        for (int i=Nt-1; i>=0; i--) {
            if (s[sIdx] == t[i]) {
                latestMatch[sIdx] = i;
                sIdx--;
            }
            if (sIdx < 0) break;
        }

        if (latestMatch[1] > 0) {
            return true;
        }

        for (int sIdx = 1; sIdx+1 < Ns && sIdx < Ns-1; sIdx++) {
            if (earliestMatch[sIdx-1] < latestMatch[sIdx+1]-1) {
                return true;
            }
        }

        if (earliestMatch[Ns-2] < Nt-1) {      
            return true;
        }
        
        return false;
    }
};