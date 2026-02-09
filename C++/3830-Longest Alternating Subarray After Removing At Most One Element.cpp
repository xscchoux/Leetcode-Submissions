class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int N = nums.size();
        // from left to right, left[i][j], i:current index, j: 0 if previous element is smaller, 1 if previous element is larger
        vector<vector<int>> left(N, vector<int>(2, 1));  
        vector<vector<int>> right(N, vector<int>(2, 1)); 
        int res = 1;
        
        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                left[i][0] = 1 + left[i-1][1];
                res = max(res, left[i][0]);
            } else if (nums[i] < nums[i-1]) {
                left[i][1] = 1 + left[i-1][0];
                res = max(res, left[i][1]);
            } else {
                left[i][0] = left[i][1] = 1;
            }
        }

        right[N-1][0] = right[N-1][1] = 1;
        for (int i=N-2; i>=0; i--) {
            if (nums[i] > nums[i+1]) {
                right[i][0] = 1 + right[i+1][1];
                res = max(res, right[i][0]);
            } else if (nums[i] < nums[i+1]) {
                right[i][1] = 1 + right[i+1][0];
                res = max(res, right[i][1]);
            } else {
                right[i][0] = right[i][1] = 1;
            }
        }

        // removing
        for (int i=1; i<N-1; i++) {
            if (nums[i-1] > nums[i+1]) {
                res = max(res, left[i-1][0] + right[i+1][1]);
            } else if (nums[i-1] < nums[i+1]) {
                res = max(res, left[i-1][1] + right[i+1][0]);
            }
        }

        return res;
    }
};



// Much faster, cache-friendly
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int N = nums.size();
        // from left to right, left[i][j], i:current index, j: 0 if previous element is smaller, 1 if previous element is larger
        vector<vector<int>> left(2, vector<int>(N, 1));  
        vector<vector<int>> right(2, vector<int>(N, 1)); 
        int res = 1;
        
        for (int i=1; i<N; i++) {
            if (nums[i] > nums[i-1]) {
                left[0][i] = 1 + left[1][i-1];
                res = max(res, left[0][i]);
            } else if (nums[i] < nums[i-1]) {
                left[1][i] = 1 + left[0][i-1];
                res = max(res, left[1][i]);
            } else {
                left[0][i] = left[1][i] = 1;
            }
        }

        right[0][N-1] = right[1][N-1] = 1;
        for (int i=N-2; i>=0; i--) {
            if (nums[i] > nums[i+1]) {
                right[0][i] = 1 + right[1][i+1];
                res = max(res, right[0][i]);
            } else if (nums[i] < nums[i+1]) {
                right[1][i] = 1 + right[0][i+1];
                res = max(res, right[1][i]);
            } else {
                right[0][i] = right[1][i] = 1;
            }
        }

        // removing
        for (int i=1; i<N-1; i++) {
            if (nums[i-1] > nums[i+1]) {
                res = max(res, left[0][i-1] + right[1][i+1]);
            } else if (nums[i-1] < nums[i+1]) {
                res = max(res, left[1][i-1] + right[0][i+1]);
            }
        }

        return res;
    }
};