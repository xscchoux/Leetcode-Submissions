class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        if (k == 0) return vector<int>(N, 0);

        int start = 1, end = k, tot = 0;
        if (k<0) {
            start = N + k;
            end = N-1;
        }

        for (int i=start; i<=end; i++) tot += code[i];
        vector<int> res(N);
        for (int i=0; i<N; i++) {
            res[i] = tot;
            tot -= code[start%N];
            tot += code[(end+1)%N];
            start++;
            end++;
        }
        return res;
    }
};