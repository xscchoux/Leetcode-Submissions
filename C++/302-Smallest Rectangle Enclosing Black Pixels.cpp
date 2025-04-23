// DFS
class Solution {
public:
    int xMin, xMax, yMin, yMax, row, col;
    void dfs(vector<vector<char>>& image, int x, int y) {
        if (x < 0 || x >= row || y<0 || y>=col || image[x][y] != '1') return;
        xMax = max(x, xMax);
        xMin = min(x, xMin);
        yMax = max(y, yMax);
        yMin = min(y, yMin);
        image[x][y] = '0';

        dfs(image, x+1, y);
        dfs(image, x, y+1);
        dfs(image, x-1, y);
        dfs(image, x, y-1);
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        this->xMin = this->xMax = x;
        this->yMin = this->yMax = y;
        this->row = image.size();
        this->col = image[0].size();

        dfs(image, x, y);

        return (xMax-xMin+1)*(yMax-yMin+1);
    }
};



// Binary search
class Solution {
public:
    int row, col;
    int minArea(vector<vector<char>>& image, int x, int y) {
        this->row = image.size();
        this->col = image[0].size();

        auto checkRow = [&](int c) {
            for (int r=0; r<row; r++) {
                if (image[r][c] == '1') return true;
            }
            return false;
        };

        auto checkCol = [&](int r) {
            for (int c=0; c<col; c++) {
                if (image[r][c] == '1') return true;
            }
            return false;
        };

        // leftMost
        int left = 0, right = y;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (checkRow(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int leftMost;
        if (checkRow(left)) leftMost = left; 
        else leftMost = right;

        // rightMost
        left = y, right = col-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (checkRow(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        int rightMost;
        if (checkRow(right)) rightMost = right; 
        else rightMost = left;

        // bottomMost
        left = x, right = row-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (checkCol(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        int bottomMost;
        if (checkCol(right)) bottomMost = right; 
        else bottomMost = left;

        // topMost
        left = 0, right = x;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (checkCol(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        int topMost;
        if (checkCol(left)) topMost = left; 
        else topMost = right;

        return (bottomMost-topMost+1)*(rightMost-leftMost+1);
    }
};