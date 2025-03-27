class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid[0].size(); c++) {
                arr.push_back(grid[r][c]);
            }
        }

        for (int i=1; i<arr.size(); i++) {
            if ((arr[i] - arr[0])%x != 0) return -1;
        }

        sort(begin(arr), end(arr));

        int median = arr[arr.size()/2], res = 0;

        for (int v:arr) {
            res += abs(v-median)/x;
        }

        return res;
    }
};