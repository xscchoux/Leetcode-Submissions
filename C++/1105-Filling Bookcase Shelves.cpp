class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int N = books.size();
        vector<int> dp(N+1, INT_MAX);
        dp[0] = 0; // minimum height when choosing the ith element
        for (int i=0; i<N; i++) {
            int currWidth = shelfWidth, height = books[i][1];            
            for (int j=i; j>=0; j--) {
                if (currWidth < books[j][0]) break;
                currWidth -= books[j][0];
                height = max(height, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + height);
            }
        }

        return dp[N];
    }
};