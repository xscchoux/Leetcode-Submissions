class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        int left = 0, right = 0;
        int res = 0;

        for (int i=0; i<N; i++) {
            if (s[i] == '(') {
                if (right) {
                    // add one right parenthesis
                    res++;
                    if (left > 0) {
                        left--;
                    } else {
                        res++;
                    }
                    right = 0;
                }
                left++;
            } else {
                right++;
                if (right >= 2) {
                    right -= 2;
                    if (left > 0) {
                        left--;
                    } else {
                        res++;
                    }
                }
            }
        }

        if (left) {
            res += 2*left-right;
        } else if (right) {
            res += 2;
        }

        return res;

    }
};