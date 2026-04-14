using LL = long long;
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> facArr;
        for (auto &fac:factory) {
            int u = fac[0], v = fac[1];
            for (int i=0; i<v; i++) {
                facArr.push_back(u);
            }
        }
        sort(facArr.begin(), facArr.end());
        sort(begin(robot), end(robot));

        int N = robot.size(), M = facArr.size();
        vector<vector<LL>> dp(N+1, vector<LL>(M+1, LLONG_MAX/3));
        for (int j=0; j<=M; j++) dp[0][j] = 0;

        for (int i=1; i<=N; i++) {
            for (int j=i; j<=M; j++) {
                dp[i][j] = min(dp[i][j-1], abs(robot[i-1] - facArr[j-1]) + dp[i-1][j-1]);
            }
        }

        return *min_element(begin(dp[N]), end(dp[N]));
    }
};



// Redo
using LL = long long;
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<int> fac;
        for (auto &f:factory) {
            for (int cnt=0; cnt<f[1]; cnt++) {
                fac.push_back(f[0]);
            }
        }
        
        int N = robot.size(), M = fac.size();
        vector<vector<LL>> dp(N+1, vector<LL>(M+1, LLONG_MAX/2));
        fill(begin(dp[0]), end(dp[0]), 0);

        for (int i=0; i<N; i++) {
            for (int j=i; j<M; j++) {
                if (j > i) {
                    dp[i+1][j+1] = dp[i+1][j];
                }

                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(robot[i] - fac[j]));
            }
        }

        return dp[N][M];
    }
};