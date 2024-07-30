class Solution {
public:
    int minimumDeletions(string s) {
        int N = s.size();
        vector<int> left(N+1, 0), right(N+1, 0);

        for (int i=0; i<N; i++) {
            if (s[i] != 'a') {
                left[i+1] = left[i]+1;
            } else {
                left[i+1] = left[i];
            }
        }

        for (int i=N-1; i>=0; i--) {
            if (s[i] != 'b') {
                right[i] = right[i+1]+1;
            } else {
                right[i] = right[i+1];
            }
        }

        int res = N;
        for (int i=0; i<=N; i++) {
            res = min(res, left[i] + right[i]);
        }

        return res;
    }
};



class Solution {
public:
    int minimumDeletions(string s) {
        int N = s.size(), res = 0, bCount = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == 'b') bCount++;
            else {
                res = min(res+1, bCount);  // (remove a) OR (keep a and remove all previous b)
            }
        }
        return res;
    }
};