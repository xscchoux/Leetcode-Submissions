class Solution {
public:
    int N;
    bool isSame(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (mat[r][c] != target[r][c]) return false;
            }
        }
        return true;
    }
    void rotate (vector<vector<int>>& mat) {
        // transpose
        for (int c=0; c<N; c++) {
            for (int r=c+1; r<N; r++) {
                swap(mat[r][c], mat[c][r]);
            }
        }
        // reverse each row
        for (int r=0; r<N; r++) {
            reverse(mat[r].begin(), mat[r].end());
        }

    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        this->N = mat.size();
        if (isSame(mat, target)) return true;

        for (int i=0; i<3; i++) {
            rotate(mat);
            if (isSame(mat, target)) {
                return true;
            }
        }

        return false;
    }
};