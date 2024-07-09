class Solution {
public:
    int uniqueLetterString(string s) {
        int N = s.size();
        int res = 0;
        vector<int> left(N, -1);

        vector<int> lastLeft(26, -1);
        for (int i=0; i<N; i++) {
            left[i] = lastLeft[s[i]-'A'];
            lastLeft[s[i]-'A'] = i;
        }

        vector<int> lastRight(26, N);
        for (int i=N-1; i>=0; i--) {
            res += (i-left[i])*(lastRight[s[i]-'A']-i);
            lastRight[s[i]-'A'] = i;
        }

        return res;
    }
};