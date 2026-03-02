class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int N = grid.size();

        vector<int> rightZeros(N, 0);

        for (int r=0; r<N; r++) {
            int cnt = 0, c = N-1;
            while (c >= 0 && grid[r][c] == 0) {
                cnt++;
                c--;
            }
            rightZeros[r] = cnt;
        }


        // greedily find the first valid row and bring it up using adjacent swap
        int swap_cnt = 0;
        for (int r=0; r<N; r++) {
            int needed = N-r-1;
            int swapR = r;
            while (swapR < N && rightZeros[swapR] < needed) {
                swapR++;
            }
            if (swapR == N) return -1;

            while (swapR > r) {
                swap(rightZeros[swapR], rightZeros[swapR-1]);
                swap_cnt++;
                swapR--;
            }
        }

        return swap_cnt;
    }
};