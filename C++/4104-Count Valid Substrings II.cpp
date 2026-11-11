class Solution {
public:
    long long countValidSubstrings(string s) {
        int N = s.size();
        long long res = 0;
        // aPos: last position of 'a'
        // pairPos: last 'a' postion of a...b
        // lastValid: last 'a' position of a...b...c
        int aPos = -1, pairPos = -1, lastValid = -1;

        for (int i=0; i<N; i++) {
            if (s[i] == 'a') {
                aPos = i;
                res += i-lastValid;
            } else if (s[i] == 'b') {
                if (aPos != -1) {
                    pairPos = aPos;
                }
                res += i-lastValid;
            } else {
                res += i - pairPos;
                if (pairPos != -1) {
                    lastValid = pairPos;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    long long countValidSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        long long res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a') {
                a = i;
            } else if (s[i] == 'b') {
                b = a;
            } else {
                c = b;
            }
            res += i-c;
        }

        return res;
    }
};