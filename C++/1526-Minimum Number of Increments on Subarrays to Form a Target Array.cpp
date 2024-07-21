class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int N = target.size();
        int inc = 0, res = 0;
        for (int i=0; i<N; i++) {
            int diff = target[i];
            if (diff > inc) {
                res += diff-inc;
            }
            inc = diff;
        }
        return res;
    }
};