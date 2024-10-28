using LL = long long;
class Solution {
public:
    LL kMod = 1e9+7;
    // const is needed here
    // Non-const lvalue references (vector<vector<int>>&) cannot accept temporaries (rvalues) because they may imply modification.
    // Const lvalue references can accept both lvalues and rvalues since they promise not to modify the input.
    vector<vector<int>> multi(const vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> res(26, vector<int>(26, 0));
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                for (int k=0; k<26; k++) {
                    res[i][j] = (res[i][j] + (LL)a[i][k]*b[k][j])%kMod;
                }
            }
        }
        return res;
    }
    vector<vector<int>> matrixPow(vector<vector<int>>& matrix, int exp) {
        if (exp == 1) return matrix;
        vector<vector<int>> base = matrixPow(matrix, exp/2);
        
        if (exp%2) {
            return multi(multi(base, base), matrix);
        } else {
            return multi(base, base);
        }
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> matrix(26, vector<int>(26, 0));
        for (int i=0; i<26; i++) {
            for (int j=1; j<=nums[i]; j++) {
                matrix[(i+j)%26][i]++;
            }
        }
        LL res = 0;
        auto tMatrix = matrixPow(matrix, t);
        vector<LL> cnt(26);
        for (char c:s) cnt[c-'a']++;
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                res = (res + tMatrix[i][j]*cnt[j])%kMod;
            }
        }
        return res;
    }
};