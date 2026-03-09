class Solution {
public:
    int minOperations(string s) {
        int N = s.size();
        if (N == 1) return 0;

        int minChar = 26, maxChar = 0;
        
        for (int i=0; i<N; i++) {
            minChar = min(minChar, s[i]-'a');
            maxChar = max(maxChar, s[i]-'a');
        }

        // if there's only one character in s
        if (maxChar == minChar) return 0;

        // if s is already sorted
        string tmp = s;
        sort(begin(tmp), end(tmp));
        if (s == tmp) return 0;

        if (s[0] == ('a' + minChar) || s.back() == ('a' + maxChar)) {

            return 1;
        } else if (s[0] == ('a' + maxChar) && s.back() == ('a' + minChar)) {
            // edge case, ex: "gf"
            if (N == 2) return -1;


            // If no mn exists in any proper prefix and no mx exists in any proper suffix, answer is 3; otherwise answer is 2

            // if s is [mx (.....) mn], and we have mx or mn in the bracket, return 2
            // else return 3
            bool found = false;
            for (int i=1; i<N-1; i++) {
                if (s[i] == ('a' + minChar) || s[i] == ('a' + maxChar)) {
                    found = true;
                    break;
                }
            }
            if (found) return 2;
            return 3;
        } else {
            return 2;
        }


        return -1;
    }
};