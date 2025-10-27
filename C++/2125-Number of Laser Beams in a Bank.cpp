class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for (auto &b:bank) {
            int cnt = count(begin(b), end(b), '1');
            res += cnt*prev;
            if (cnt != 0) prev = cnt;
        }

        return res;

    }
};