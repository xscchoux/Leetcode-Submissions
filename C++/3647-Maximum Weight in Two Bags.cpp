// O(N*w1*w2)
class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        
        vector<vector<int>> prev(w1+1, vector<int>(w2+1, 0)), curr(w1+1, vector<int>(w2+1, 0));
        prev[0][0] = curr[0][0] = 1;

        // 2D Knapsack DP
        for (int i=0; i<weights.size(); i++) {
            // put weights[i] in bag2
            for (int r=0; r<=w1; r++) {
                for (int c=w2; c>=0; c--) {
                    if (c < weights[i]) break;
                    curr[r][c] |= prev[r][c-weights[i]];
                }
            }
            // put weights[i] in bag1
            for (int c=0; c<=w2; c++) {
                for (int r=w1; r>=0; r--) {
                    if (r < weights[i]) break;
                    curr[r][c] |= prev[r-weights[i]][c];
                }
            }

            prev = curr;
        }

        int res = 0;
        for (int r=0; r<=w1; r++) {
            for (int c=0; c<=w2; c++) {
                if (prev[r][c] == 1) res = max(res, r+c);
            }
        }

        return res;
    }
};



// use bitset, much faster
// O(N*w1*O(w2/word_size))

// word_size means the number of bits that the CPU (and also std::bitset) processes at once in its underlying storage type.
// On a 32-bit system, a “word” is usually 32 bits.
// On a 64-bit system, a “word” is usually 64 bits.

class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        vector<bitset<301>> prev(w1+1), curr(w1+1);
        prev[0][0] = curr[0][0] = 1;

        // 2D Knapsack DP
        for (int i=0; i<weights.size(); i++) {
            // put weights[i] in bag2
            if (weights[i] <= w2) {
                for (int r=0; r<=w1; r++) {
                    curr[r] |= (prev[r] << weights[i]);
                }
            }

            // put weights[i] in bag1
            if (weights[i] <= w1) {
                for (int r=w1; r>=weights[i]; r--) {
                    curr[r] |= prev[r-weights[i]];
                }
            }
            prev = curr;
        }

        int res = 0;
        for (int r=0; r<=w1; r++) {
            for (int c=0; c<=w2; c++) {
                if (prev[r][c]) res = max(res, r+c);
            }
        }

        return res;
    }
};