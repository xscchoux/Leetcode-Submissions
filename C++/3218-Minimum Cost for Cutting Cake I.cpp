class Solution {
public:
    vector<int> H, V;
    int m, n;
    int dp[21][21][21][21];
    int cal(int r1, int r2, int c1, int c2) {
        if (r1 > r2 || c1 > c2) return 0;
        if (dp[r1][r2][c1][c2] != -1) return dp[r1][r2][c1][c2];
        int res = INT_MAX;

        for (int r=r1; r<r2; r++) {
            res = min(res, H[r] + cal(r1, r, c1, c2) + cal(r+1, r2, c1, c2));
        }
        for (int c=c1; c<c2; c++) {
            res = min(res, V[c] + cal(r1, r2, c1, c) + cal(r1, r2, c+1, c2));
        }

        return dp[r1][r2][c1][c2] = (res < INT_MAX)?res:0;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int res = INT_MAX;
        this->H = horizontalCut;
        this->V = verticalCut;
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        
        for (int r=0; r<m-1; r++) {
            res = min(res, H[r] + cal(0, r, 0, n-1) + cal(r+1, m-1, 0, n-1));
        }
        for (int c=0; c<n-1; c++) {
            res = min(res, V[c] + cal(0, m-1, 0, c) + cal(0, m-1, c+1, n-1));
        }

        return (res < INT_MAX)?res:0;
    }
};