class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> tot(N, 1);

        // increase candies only when rating increases, no operations otherwise 

        for (int i=1; i<N; i++) {
            if (ratings[i] > ratings[i-1]) {
                tot[i] = tot[i-1] + 1;
            }
        }

        for (int i=N-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                tot[i] = max(tot[i], tot[i+1] + 1);
            }
        }

        return accumulate(begin(tot), end(tot), 0);
    }
};