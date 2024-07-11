class Solution {
public:
    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        // arr with even set bits XOR arr with even set bits -> arr with even set bits
        // arr with even set bits XOR arr with odd set bits  -> arr with odd set bits
        // arr with odd set bits XOR arr with odd set bits   -> arr with even set bits
        // The answer = (all even set bits array) + (1 even set bits array and 2 odd set bits array)

        vector<long long> cntA(2);
        vector<long long> cntB(2);
        vector<long long> cntC(2);
        long long res = 0;

        for (int num:a) {
            int cnt =  __builtin_popcount(num);
            cntA[cnt%2]++;
        }

        for (int num:b) {
            int cnt =  __builtin_popcount(num);
            cntB[cnt%2]++;
        }

        for (int num:c) {
            int cnt =  __builtin_popcount(num);
            cntC[cnt%2]++;
        }

        res += cntA[0]*cntB[0]*cntC[0] + cntA[1]*cntB[1]*cntC[0] + cntA[1]*cntB[0]*cntC[1] + cntA[0]*cntB[1]*cntC[1];

        return res;
    }
};