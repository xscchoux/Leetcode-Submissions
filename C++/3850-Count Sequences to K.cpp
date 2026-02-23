// backtracking, TLE
class Solution {
public:
    long long k;
    int res = 0, N;
    bool dfs(int idx, vector<int>& nums, long long nominator, long long denominator, vector<long long>& mul) {
        if (idx == N) {
            if (nominator%denominator == 0 && nominator/denominator == k) {
                res++;
            }
            return true;
        }

        // pruning
        if (nominator*mul[idx] < k*denominator) {
            return false;
        }

        // multiply
        if (dfs(idx+1, nums, nominator*nums[idx], denominator, mul)) {
            // skip
            if (dfs(idx+1, nums, nominator, denominator, mul)) {
                // divide
                dfs(idx+1, nums, nominator, denominator*nums[idx], mul);
            }
        }

        return true;
    }
    int countSequences(vector<int>& nums, long long k) {
        this->k = k;
        this->N = nums.size();

        vector<long long> mul(N, 1);
        mul[N-1] = nums[N-1];
        for (int i=N-2; i>=0; i--) {
            mul[i] = mul[i+1]*nums[i];
        }
        

        dfs(0, nums, 1, 1, mul);

        return res;
    }
};



// bottom-up DP, with some tricks
class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        int N = nums.size();
        vector<array<int, 3>> arr(N);
        array<int, 3> primes = {2,3,5};
        vector<int> kFactors(3, 0);

        long long tmpK = k;
        for (int i=0; i<primes.size(); i++) {
            while (tmpK > 1 && tmpK%primes[i] == 0) {
                tmpK = tmpK/primes[i];
                kFactors[i]++;
            }
        }

        // k should only consist of 2, 3, 5
        if (tmpK > 1) return 0;

        // nums.size() <= 19
        if (kFactors[0] > 38 || kFactors[1] > 19 || kFactors[2] > 19) return 0;

        long long mul =1;
        for (int i=0; i<nums.size(); i++) {
            mul *= nums[i];
            int tmpNum = nums[i];
            for (int j=0; j<primes.size(); j++) {
                while (tmpNum > 0 && tmpNum%primes[j] == 0) {
                    tmpNum /= primes[j];
                    arr[i][j]++;
                }
            }
        }

        // multiplication of all items should  >= k
        if (mul < k) return 0;

        int dp[21][77][39][39] = {0};
        dp[0][38][19][19] = 1;

        for (int i=0; i<N; i++) {
            int curr2 = arr[i][0], curr3 = arr[i][1], curr5 = arr[i][2];
            for (int a=38-2*(i+1); a<=38+2*(i+1); a++) {
                for (int b=19-(i+1); b<=19+(i+1); b++) {
                    for (int c=19-(i+1); c<=19+(i+1); c++) {
                        // skip
                        dp[i+1][a][b][c] += dp[i][a][b][c];
                        // multiply
                        if (a-curr2>=0 && b-curr3>=0 && c-curr5>=0) dp[i+1][a][b][c] += dp[i][a-curr2][b-curr3][c-curr5];
                        // divide
                        if (a+curr2<76 && b+curr3<38 && c+curr5<38) dp[i+1][a][b][c] += dp[i][a+curr2][b+curr3][c+curr5];
                    }
                }
            }
        }

        return dp[N][38+kFactors[0]][19+kFactors[1]][19+kFactors[2]];
    }
};



// top-down DP with pruning and a GCD trick
class Solution {
public:
    long long k;
    int res = 0, N;
    long long dfs(int idx, vector<int>& nums, long long nominator, long long denominator, vector<long long>& mul, vector<map<pair<long long, long long>, int>>& dp) {
        long long g = __gcd(nominator, denominator);
        nominator /= g;
        denominator /= g;

        if (idx == N) {
            if (nominator%denominator == 0 && nominator/denominator == k) {
                return 1;
            }
            return 0;
        }

        if (dp[idx].contains({nominator, denominator})) {
            return dp[idx][{nominator, denominator}];
        }

        // pruning
        if (nominator*mul[idx] < k*denominator) {
            return 0;
        }

        long long skip = dfs(idx+1, nums, nominator, denominator, mul, dp);
        long long divide = dfs(idx+1, nums, nominator, denominator*nums[idx], mul, dp);
        long long multiply = dfs(idx+1, nums, nominator*nums[idx], denominator, mul, dp);

        return dp[idx][{nominator, denominator}] = skip + divide + multiply;
    }
    int countSequences(vector<int>& nums, long long k) {
        this->k = k;
        this->N = nums.size();

        vector<long long> mul(N, 1);
        mul[N-1] = nums[N-1];
        for (int i=N-2; i>=0; i--) {
            mul[i] = mul[i+1]*nums[i];
        }

        vector<map<pair<long long, long long>, int>> dp(N);


        long long res = dfs(0, nums, 1, 1, mul, dp);

        return res;
    }
};