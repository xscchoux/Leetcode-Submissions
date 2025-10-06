// https://github.com/wisdompeak/LeetCode/tree/master/Math/3700.Number-of-ZigZag-Arrays-II
using LL = long long;
LL kMod = 1e9+7;

class Solution {
public:
    int diff;
    vector<vector<LL>> multi(const vector<vector<LL>>& a, const vector<vector<LL>>& b) {
        int side = 2*(diff+1);
        vector<vector<LL>> res(side, vector<LL>(side, 0));
        for (int i=0; i<side; i++) {
            for (int j=0; j<side; j++) {
                for (int k=0; k<side; k++) {
                    res[i][j] = (res[i][j] + (LL)a[i][k]*b[k][j])%kMod;
                }
            }
        }
        return res;
    }
    vector<vector<LL>> matrixPow(vector<vector<LL>>& matrix, int t) {
        if (t == 1) return matrix;
        vector<vector<LL>> base = matrixPow(matrix, t/2);
        if (t%2) {
            return multi(multi(base, base), matrix);
        } else {
            return multi(base, base);
        }
    }

    int zigZagArrays(int n, int l, int r) {
        this->diff = r-l+1;
        vector<vector<LL>> T(2*(diff+1), vector<LL>(2*(diff+1), 0));
        // up[i][curr] = down[i-1][1] + ... + down[i-1][curr-1]   curr: peak value
        // down[i][curr] = up[i-1][diff] + ... + up[i-1][curr+1]  curr: valley value


        // T:
        // ............... 0
        //                 1 0
        //                 1 1 0
        //                 ...
        //                 1 1 1 .. 1 1 0
        // 1 1 1 .. 1 1 0  ...........
        // ...
        // 1 1 0
        // 1 0
        // 0

        // initial result (vector)
        // up[0] = 1
        // up[1] = 1
        //  .
        //  .
        //  .
        // down[0] = 1
        // down[1] = 1

        // We want to get T^(n-1) * (initial result)

        // fill T for up values
        for (int curr=1; curr<=diff; curr++) {
            for (int c=1; c<curr; c++) {
                T[diff+1+curr][c] = 1;
            }
        }

        // fill T for down values
        for (int curr=1; curr<=diff; curr++) {
            for (int c=diff; c>curr; c--) {
                T[curr][diff+1+c] = 1;
            }
        }

        vector<vector<LL>> newT = matrixPow(T, n-1);

        LL res = 0;
        for (int r=0; r<newT.size(); r++) {
            for (int c=0; c<newT[0].size(); c++) {
                if (newT[r][c]) {
                    res = (res+newT[r][c])%kMod;
                }
            }
        }

        return res;
    }
};