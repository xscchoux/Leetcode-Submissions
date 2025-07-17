// https://github.com/wisdompeak/LeetCode/tree/master/Dynamic_Programming/1900.The-Earliest-and-Latest-Rounds-Where-Players-Compete
// First AC
class Solution {
public:
    int dfs2(int number, int a, int b, vector<vector<vector<int>>>& dp) {
        // This is not needed. a is always smaller than b
        // if (a > b) {
        //     return dfs2(number, b, a, dp);
        // }
        if ((a+b) > (number+1)) {
            return dfs2(number, number-b+1, number-a+1, dp);
        }

        if (a == number-b+1) {
            return 1;
        }

        if (dp[number][a][b] != -1) {
            return dp[number][a][b];
        }

        int res = -1;
        // case 1, when b is greater than mid point
        if (2*b > (number+1)) {
            int mirror_b = number-b+1;
            int x = a - 1, y = mirror_b-a-1;
            for (int xx=0; xx<=x; xx++) {
                for (int yy=0; yy<=y; yy++) {
                    res = max(res, 1+dfs2((number+1)/2, a-xx, b-xx-yy-(b-mirror_b-1)/2-1, dp));
                }
            }
        } else { // case2, when b is less than or equal to the mid point
            int x = a - 1, y = b-a-1;
            for (int xx=0; xx<=x; xx++) {
                for (int yy=0; yy<=y; yy++) {
                    res = max(res, 1+dfs2((number+1)/2, a-xx, b-xx-yy, dp));
                }
            }
        }
        return dp[number][a][b] = res;
    }
    int dfs(int number, int a, int b, vector<vector<vector<int>>>& dp) {
        // This is not needed. a is always smaller than b
        // if (a > b) {
        //     return dfs(number, b, a, dp);
        // }
        if ((a+b) > (number+1)) {
            return dfs(number, number-b+1, number-a+1, dp);
        }

        if (a == number-b+1) {
            return 1;
        }

        if (dp[number][a][b] != INT_MAX) {
            return dp[number][a][b];
        }

        int res = number;
        // case 1, when b is greater than mid point
        if (2*b > (number+1)) {
            int mirror_b = number-b+1;
            int x = a - 1, y = mirror_b-a-1;
            for (int xx=0; xx<=x; xx++) {
                for (int yy=0; yy<=y; yy++) {
                    res = min(res, 1+dfs((number+1)/2, a-xx, b-xx-yy-(b-mirror_b-1)/2-1, dp));
                }
            }
        } else { // case2, when b is less than or equal to the mid point
            int x = a - 1, y = b-a-1;
            for (int xx=0; xx<=x; xx++) {
                for (int yy=0; yy<=y; yy++) {
                    res = min(res, 1+dfs((number+1)/2, a-xx, b-xx-yy, dp));
                }
            }
        }
        return dp[number][a][b] = res;
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // dp1[n][a][b], minimum rounds needed to make a and b compete
        // dp2[n][a][b], maximum rounds needed to make a and b compete

        vector<vector<vector<int>>> dp1(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX)));
        vector<vector<vector<int>>> dp2(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));

        int res1 = dfs(n, firstPlayer, secondPlayer, dp1);
        int res2 = dfs2(n, firstPlayer, secondPlayer, dp2);

        return {res1, res2};
    }
};


class Solution {
public:
    pair<int, int> dfs(int number, int a, int b, vector<vector<vector<int>>>& dp1, vector<vector<vector<int>>>& dp2) {
        // This is not needed. a is always smaller than b
        // if (a > b) {
        //     return dfs(number, b, a, dp1, dp2);
        // }

        // When (a+b)/2 is greater than the mid point
        if ((a+b) > (number+1)) {
            return dfs(number, number-b+1, number-a+1, dp1, dp2);
        }

        if (a == number-b+1) {
            return {1, 1};
        }

        if (dp1[number][a][b] != INT_MAX) {
            return {dp1[number][a][b], dp2[number][a][b]};
        }

        int res1 = number, res2 = 0;
        // case 1, when b is greater than mid point
        if (2*b > (number+1)) {
            int mirror_b = number-b+1;
            int x = a - 1, y = mirror_b-a-1;
            for (int xx=0; xx<=x; xx++) {
                for (int yy=0; yy<=y; yy++) {
                    auto tmp = dfs((number+1)/2, a-xx, b-xx-yy-(b-mirror_b-1)/2-1, dp1, dp2);
                    res1 = min(res1, 1+tmp.first);
                    res2 = max(res2, 1+tmp.second);
                }
            }
        } else { // case2, when b is less than or equal to the mid point
            int x = a - 1, y = b-a-1;
            for (int xx=0; xx<=x; xx++) {
                for (int yy=0; yy<=y; yy++) {
                    auto tmp = dfs((number+1)/2, a-xx, b-xx-yy, dp1, dp2);
                    res1 = min(res1, 1+tmp.first);
                    res2 = max(res2, 1+tmp.second);
                    // res = min(res, 1+dfs((number+1)/2, a-xx, b-xx-yy, dp));
                }
            }
        }
        dp1[number][a][b] = res1;
        dp2[number][a][b] = res2;
        return {res1, res2};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // dp1[n][a][b], minimum rounds needed to make a and b compete
        // dp2[n][a][b], maximum rounds needed to make a and b compete

        vector<vector<vector<int>>> dp1(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX)));
        vector<vector<vector<int>>> dp2(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));

        auto [res1, res2] = dfs(n, firstPlayer, secondPlayer, dp1, dp2);
        return {res1, res2};
    }
};