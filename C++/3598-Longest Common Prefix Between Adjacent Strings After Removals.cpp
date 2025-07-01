class Solution {
public:
    int countPrefix(string& s1, string& s2) {
        int i1 = 0, i2 = 0;
        int res = 0;
        while (i1 < s1.size() && i2 < s2.size()) {
            if (s1[i1] != s2[i2]) break;
            res++;
            i1++;i2++;
        }

        return res;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int N = words.size();
        if (N == 1) return {0};
        vector<int> rightLongest(N, 0), leftLongest(N, 0);

        for (int i=N-2; i>=0; i--) {
            rightLongest[i] = max(rightLongest[i+1], countPrefix(words[i], words[i+1]));
        }

        for (int i=1; i<N; i++) {
            leftLongest[i] = max(leftLongest[i-1], countPrefix(words[i], words[i-1]));
        }

        vector<int> res;

        for (int i=0; i<N; i++) {
            int prefix = 0;
            if (i == 0) {
                res.push_back(rightLongest[i+1]);
            } else if (i == N-1) {
                res.push_back(leftLongest[i-1]);
            } else {
                res.push_back(max({countPrefix(words[i+1], words[i-1]), leftLongest[i-1], rightLongest[i+1]}));
            }
        }

        return res;
    }
};