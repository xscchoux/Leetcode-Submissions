// First AC
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool reverse = false;
        int row = mat.size(), col = mat[0].size();
        vector<int> res;

        for (int sum = 0; sum <= row+col-2; sum++) {
            if (reverse) {
                for (int c=min(sum, col-1); sum-c<=row-1 && c >=0; c--) {
                    int r = sum-c;
                    res.push_back(mat[r][c]);
                }
            } else {
                for (int r=min(sum, row-1); sum-r<=col-1 && r>=0; r--) {
                    int c = sum-r;
                    res.push_back(mat[r][c]);
                }
            }
            reverse = !reverse;
        }
        
        return res;
    }
};


// O(row*col)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int r=0, c=0;
        vector<int> res;

        while (res.size() < row*col) {
            res.push_back(mat[r][c]);

            if ((r+c)%2 == 0) {
                if (c == col-1) {
                    r++;
                } else if (r == 0) {
                    c++;
                } else {
                    c++;
                    r--;
                }
            } else {
                if (r == row-1) {
                    c++;
                } else if (c == 0) {
                    r++;
                } else {
                    c--;
                    r++;
                }                
            }
        }

        return res;
    }
};