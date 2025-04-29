// compress mat1
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        map<pair<int, int>, int> hmap;
        int row1 = mat1.size(), col1 = mat1[0].size();

        for (int r=0; r<row1; r++) {
            for (int c=0; c<col1; c++) {
                hmap[{r, c}] = mat1[r][c];
            }
        }

        vector<vector<int>> res(row1, vector<int>(mat2[0].size(), 0));

        for (auto &[rc, val]:hmap) {
            int r1 = rc.first, c1 = rc.second;
            for (int c2=0; c2<mat2[0].size(); c2++) {
                if (mat2[c1][c2]) {
                    res[r1][c2] += val*mat2[c1][c2];
                }
            }
        }

        return res;
    }
};


// compress both matrixes, clever one
class Solution {
public:
    vector<vector<pair<int, int>>> compressed(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<pair<int, int>>> compressedMatrix(row);
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (mat[r][c] != 0) {
                    compressedMatrix[r].push_back({mat[r][c], c});
                }
            }
        }
        return compressedMatrix;
    }
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int row1 = mat1.size(), col1 = mat1[0].size();
        auto A = compressed(mat1), B = compressed(mat2);

        vector<vector<int>> res(row1, vector<int>(mat2[0].size(), 0));

        for (int r=0; r<row1; r++) {
            for (auto [val1, col1]:A[r]) {
                for (auto [val2, col2]:B[col1]) {
                    res[r][col2] += val1*val2;
                }
            }
        }

        return res;
    }
};