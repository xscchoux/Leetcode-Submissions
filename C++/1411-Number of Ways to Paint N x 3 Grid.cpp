// Stupid row-wise DP
class Solution {
public:
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(3, 0))));
        int kMod = 1e9+7;
        // first row
        for (int c1=0; c1<3; c1++) {
            for (int c2=0; c2<3; c2++) {
                if (c1 == c2) continue;
                for (int c3=0; c3<3; c3++) {
                    if (c2 == c3) continue;
                    dp[0][c1][c2][c3]++;
                }
            }
        }

        for (int r=1; r<n; r++) {
            for (int c1=0; c1<3; c1++) {
                for (int c2=0; c2<3; c2++) {
                    if (c1 == c2) continue;
                    for (int c3=0; c3<3; c3++) {
                        if (c2 == c3) continue;
                        // fixed c1, c2, c3, now find cc1, cc2, cc3 from previous row
                        for (int cc1=0; cc1<3; cc1++) {
                            for (int cc2=0; cc2<3; cc2++) {
                                if (cc1 == cc2) continue;
                                for (int cc3=0; cc3<3; cc3++) {
                                    if (cc2 == cc3) continue;
                                    if (c1 != cc1 && c2 != cc2 && c3 != cc3) {
                                        dp[r][c1][c2][c3] = (dp[r][c1][c2][c3] + dp[r-1][cc1][cc2][cc3])%kMod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        long long res = 0;
        for (int c1=0; c1<3; c1++) {
            for (int c2=0; c2<3; c2++) {
                if (c1 == c2) continue;
                for (int c3=0; c3<3; c3++) {
                    if (c2 == c3) continue;
                    res = (res + dp[n-1][c1][c2][c3])%kMod;
                }
            }
        }       

        return res;
    }
};


// O(n)
// same: 010, 121, 212, ....
// diff: 012, 120, 021, ....
class Solution {
public:
    int numOfWays(int n) {
        int same = 6, diff = 6, kMod = 1e9+7;

        for (int r=1; r<n; r++) {
            long long prevSame = same, prevDiff = diff;
            same = (2*prevDiff + 3*prevSame)%kMod;
            diff = (2*prevSame + 2*prevDiff)%kMod;
        }

        return (same + diff)%kMod;
    }
};



// Fast Pow, O(logn)
class Solution {
public:
    int kMod = 1e9+7;
    vector<vector<int>> multi(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        vector<vector<int>> res(2, vector<int>(2, 0));
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    res[i][j] = (res[i][j] + (long long)a[i][k]*b[k][j])%kMod;
                }
            }
        }
        return res;
    }
    vector<vector<int>> matrixPow(vector<vector<int>>& matrix, int t) {
        if (t == 1) return matrix;
        vector<vector<int>> base = matrixPow(matrix, t/2);
        if (t%2) {
            return multi(multi(base, base), matrix);
        } else {
            return multi(base, base);
        }
    }
    int numOfWays(int n) {
        if (n == 1) return 12;
        long same = 6, diff = 6;

        vector<vector<int>> matrix = {{3, 2}, {2, 2}};

        matrix = matrixPow(matrix, n-1);         

        return (same*(matrix[0][0] + matrix[1][0])%kMod + diff*(matrix[0][1]+matrix[1][1])%kMod)%kMod;
    }
};