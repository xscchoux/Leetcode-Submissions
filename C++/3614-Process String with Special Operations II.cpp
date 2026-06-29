class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        int N = s.size();
        
        // get the length of the final string
        for (int i=0; i<N; i++) {
            if (s[i] == '*') {
                length = max(length-1, 0LL);
            } else if (s[i] == '#') {
                length = length*2;
            } else if (s[i] == '%') {
                continue;
            } else {
                length++;
            }
        }

        if (k > length-1) {
            return '.';
        }

        // simulation, walk backwards
        for (int i=N-1; i>=0; i--) {
            if (s[i] == '*') {
                length++;
            } else if (s[i] == '#') {
                if (k >= length/2) {
                    k -= length/2;
                }
                length = length/2;
            } else if (s[i] == '%') {
                k = length - k - 1;
            } else {
                if (k == length-1) {
                    return s[i];
                } else {
                    length--;
                }
            }
        }

        return '.';
    }
};