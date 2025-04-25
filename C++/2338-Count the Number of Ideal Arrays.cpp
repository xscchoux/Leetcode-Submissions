using LL = long long;
const int kMod = 1e9+7;
const int MAX_VALUE = 1e4;
const int MAX_PRIME_CNT = 13; // max number of a certain prime. Use 13 since 2^13 < 1e4
vector<vector<int>> primeCnt(MAX_VALUE+1); // an array of vectors, giving count of primes for each number 1~maxN
vector<vector<int>> nCr(MAX_VALUE + MAX_PRIME_CNT + 1, vector<int>(MAX_VALUE+1, 0)); 

auto init = []() {
    // fill primeCnt
    for (int num=2; num<=MAX_VALUE; num++) {
        int tmp = num;
        for (int i=2; i*i<=tmp; i++) {
            int cnt = 0;
            while (tmp%i == 0) {
                tmp /= i;
                cnt++;
            }
            if (cnt > 0) {
                primeCnt[num].push_back(cnt);
            }
        }
        if (tmp > 1) {
            primeCnt[num].push_back(1);
        }
    }
    
    // fill nCr, nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1]
    nCr[0][0] = 1;
    for (int i=1; i<=MAX_VALUE + MAX_PRIME_CNT; i++) {
        nCr[i][0] = 1;
        for (int j=1; j<=min(i, MAX_VALUE); j++) {
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%kMod; 
        }
    }

    return 0;
}();   // note "()" here

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int res = 0;

        for (int endValue = 1; endValue<=maxValue; endValue++) {
            LL tmp = 1;
            for (int factorCnt:primeCnt[endValue]) {
                tmp = (tmp*nCr[factorCnt+n-1][factorCnt])%kMod;
            }
            res = (res + tmp)%kMod;
        }

        return res;
    }
};