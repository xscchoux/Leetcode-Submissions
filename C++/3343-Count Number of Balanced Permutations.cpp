const int kMod = 1e9+7;
const int MAX_N = 40;
using LL = long long;
vector<vector<LL>> nCr(MAX_N+1, vector<LL>(MAX_N+1, 0));

int fillVector = []() {
    // fill nCr
    nCr[0][0] = 1;
    for (int n=1; n<=MAX_N; n++) {
        nCr[n][0] = 1;
        for (int r=1; r<=min(n, r); r++) {
            nCr[n][r] = (nCr[n-1][r] + nCr[n-1][r-1])%kMod;
        }
    }
    return 0;
}();

class Solution {
public:
    int N, tot = 0;
    int memo[10][41][41][361];
    int dfs(int currNum, int odd, int even, int oddSum, vector<int>& cnt) {  // currNum: current number from 0 to 9, odd: odd positions, even: even positions
        if (currNum < 0) {
            if (oddSum == tot/2) return 1;
            return 0;
        }

        if (memo[currNum][odd][even][oddSum] != -1) return memo[currNum][odd][even][oddSum];

        LL res = 0;
        for (int k=0; k<=cnt[currNum]; k++) {
            // put k currNums in odd positions, and put (cnt[num] - k) currNums in even positions
            if (oddSum + currNum*k > tot/2) break;
            if (odd-k<0 || even-(cnt[currNum]-k) < 0) continue;
            res = (res + ((nCr[odd][k]*nCr[even][cnt[currNum]-k])%kMod)*dfs(currNum-1, odd-k, even-(cnt[currNum]-k), oddSum + currNum*k, cnt))%kMod;
        }

        return memo[currNum][odd][even][oddSum] = res;
    }
    int countBalancedPermutations(string num) {
        vector<int> cnt(10);
        N = num.size();
        for (char c:num) {
            cnt[c-'0']++;
            tot += c-'0';
        }

        if (tot%2) return 0;
        int half = tot/2, oddCnt = N/2, evenCnt = N-N/2;
        memset(memo, -1, sizeof(memo));

        return dfs(9, N/2, N-N/2, 0, cnt);
    }
};



// Made little change
const int kMod = 1e9+7;
const int MAX_N = 40;
using LL = long long;
vector<vector<LL>> nCr(MAX_N+1, vector<LL>(MAX_N+1, 0));

int fillVector = []() {
    // fill nCr
    nCr[0][0] = 1;
    for (int n=1; n<=MAX_N; n++) {
        nCr[n][0] = 1;
        for (int r=1; r<=min(n, r); r++) {
            nCr[n][r] = (nCr[n-1][r] + nCr[n-1][r-1])%kMod;
        }
    }
    return 0;
}();

class Solution {
public:
    int N, tot = 0;
    int memo[10][41][41][361];
    int dfs(int currNum, int odd, int even, int oddSum, vector<int>& cnt) {  // currNum: current number from 0 to 9, odd: odd positions, even: even positions
        if (currNum < 0) {
            if (oddSum == tot/2) return 1;
            return 0;
        }

        if (memo[currNum][odd][even][oddSum] != -1) return memo[currNum][odd][even][oddSum];

        LL res = 0;
        for (int k=max(0, cnt[currNum]-even); k<=min(cnt[currNum], odd); k++) {
            // put k currNums in odd positions, and put (cnt[num] - k) currNums in even positions
            if (oddSum + currNum*k > tot/2) break;
            res = (res + ((nCr[odd][k]*nCr[even][cnt[currNum]-k])%kMod)*dfs(currNum-1, odd-k, even-(cnt[currNum]-k), oddSum + currNum*k, cnt))%kMod;
        }

        return memo[currNum][odd][even][oddSum] = res;
    }
    int countBalancedPermutations(string num) {
        vector<int> cnt(10);
        N = num.size();
        for (char c:num) {
            cnt[c-'0']++;
            tot += c-'0';
        }

        if (tot%2) return 0;
        memset(memo, -1, sizeof(memo));

        return dfs(9, N/2, N-N/2, 0, cnt);
    }
};