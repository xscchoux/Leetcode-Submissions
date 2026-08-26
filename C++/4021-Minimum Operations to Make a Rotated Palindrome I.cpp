class Solution {
public:
    int N;
    int cal(string& s) {
        int tot = 0;        
        for (int i=0; i<N/2; i++) {
            int diff = abs(s[i]-s[N-i-1]);
            tot += min(diff, 26-diff);
        }
        return tot;
    }
    int minOperations(string s) {
        this->N = s.size();

        int res = cal(s);

        for (int i=1; i<N; i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            res = min(res, i+cal(s));
        }

        return res;
    }
};