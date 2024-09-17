class Solution {
public:
    int dp[101][101][101];  // # left index, right index, count of numbers same with boxes[left] (do not include boxes[left] itself)
    int N;
    int dfs(int left, int right, int same, vector<int>& boxes) {
        if (left > right) return 0;
        if (dp[left][right][same] != -1) return dp[left][right][same];

        int res = dfs(left+1, right, 0, boxes) + (same+1)*(same+1);

        for (int i=left+1; i<=right; i++) {
            if (boxes[i] == boxes[left]) {
                res = max(res, dfs(left+1, i-1, 0, boxes) + dfs(i, right, same+1, boxes));
            }
        }

        return dp[left][right][same] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        this->N = boxes.size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, N-1, 0, boxes);
    }
};

// Better
class Solution {
public:
    int dp[101][101][101];
    int N;
    int dfs(int left, int right, int same, vector<int>& boxes) {
        if (left > right) return 0;
        if (dp[left][right][same] != -1) return dp[left][right][same];

        int count = same;
        int tmpL = left;
        while (tmpL <= right && boxes[tmpL] == boxes[left]) {
            tmpL++;
            count++;
        }
        int res = dfs(tmpL, right, 0, boxes) + count*count;

        for (int i=tmpL; i<=right; i++) {
            if (boxes[i] == boxes[left]) {
                res = max(res, dfs(tmpL, i-1, 0, boxes) + dfs(i, right, count, boxes));
            }
        }

        return dp[left][right][same] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        this->N = boxes.size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, N-1, 0, boxes);
    }
};


// Even better
class Solution {
public:
    int dp[101][101][101];
    int N;
    int dfs(int left, int right, int same, vector<int>& boxes) {
        if (left > right) return 0;
        if (dp[left][right][same] != -1) return dp[left][right][same];

        int count = same;
        int tmpL = left;
        while (tmpL <= right && boxes[tmpL] == boxes[left]) {
            tmpL++;
            count++;
        }
        int res = dfs(tmpL, right, 0, boxes) + count*count;

        for (int i=tmpL; i<=right; i++) {
            if (boxes[i] == boxes[i-1] && boxes[i] == boxes[left]) continue;  // This is brilliant
            if (boxes[i] == boxes[left]) {
                res = max(res, dfs(tmpL, i-1, 0, boxes) + dfs(i, right, count, boxes));
            }
        }

        return dp[left][right][same] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        this->N = boxes.size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, N-1, 0, boxes);
    }
};




