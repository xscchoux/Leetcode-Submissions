class Solution {
public:
    long long cnt(int num) {
        long long curr = 1;
        long long res = 0;
        while (curr <= num) {
            res += num-curr+1;
            curr *= 4;
        }
        return res;
    } 
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for (auto &q:queries) {
            int start = q[0], end = q[1];
            long long op = cnt(end) - cnt(start-1);
            res += (op+1)/2;
        }
        return res;
    }
};