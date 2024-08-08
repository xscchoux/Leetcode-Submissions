class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int up=0, down=0, left=0, right=0, N = rows*cols;
        
        int currR = rStart, currC = cStart;
        res.push_back({rStart, cStart});

        while (true) {
            int moveRight = 0;
            right = left+1;
            while (moveRight < right) {
                currC++;
                if (0<=currR && currR<rows && 0<=currC && currC<cols) {
                    res.push_back({currR, currC});
                }
                moveRight++;
            }

            if (res.size() == N) break;

            int moveDown = 0;
            down = up+1;
            while (moveDown < down) {
                currR++;
                if (0<=currR && currR<rows && 0<=currC && currC<cols) {
                    res.push_back({currR, currC});
                }
                moveDown++;
            }

            if (res.size() == N) break;

            int moveLeft = 0;
            left = right+1;
            while (moveLeft < left) {
                currC--;
                if (0<=currR && currR<rows && 0<=currC && currC<cols) {
                    res.push_back({currR, currC});
                }
                moveLeft++;
            }

            if (res.size() == N) break;

            int moveUp = 0;
            up = down+1;
            while (moveUp < up) {
                currR--;
                if (0<=currR && currR<rows && 0<=currC && currC<cols) {
                    res.push_back({currR, currC});
                }
                moveUp++;
            }

            if (res.size() == N) break;
        }

        return res;
    }
};