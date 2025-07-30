class Solution {
public:
    long long numOfSubsequences(string s) {
        long long res = 0;
        int N = s.size();
        
        // total without inserting
        long long Lcnt = 0, Ccnt = 0, Tcnt = 0, LCpair = 0;
        long long curr = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == 'L') {
                Lcnt++;
            } else if (s[i] == 'C') {
                LCpair += Lcnt;
            } else if (s[i] == 'T') {
                Tcnt += 1;
                curr += LCpair;
            }
        }

        // insert C
        long long addC = 0;
        Lcnt = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == 'L') {
                Lcnt += 1;
                addC = max(addC, Lcnt*Tcnt);
            } else if (s[i] == 'T') {
                Tcnt--;
            }
        }

        // insert L
        long long addL = 0;
        LCpair = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == 'C') {
                LCpair += 1;
            } else if (s[i] == 'T') {
                addL += LCpair;
            }
        }


        // insert T
        long long addT = 0;
        Lcnt = 0;
        Ccnt = 0;
        LCpair = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == 'L') {
                Lcnt += 1;
            } else if (s[i] == 'C') {
                LCpair += Lcnt;
            }
        }
        addT = LCpair;

        return curr + max({addC, addL, addT});
    }
};