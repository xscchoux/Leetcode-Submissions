// DP, much slower
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int N = tops.size();
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(7, vector<int>(2, INT_MAX)));  // dp[idx][number][top:0, down:1]
        for (int num=1; num<=6; num++) {
            dp[0][num][0] = dp[0][num][1] = 0;
        }

        for (int i=1; i<=N; i++) {
            int topNum = tops[i-1], bottomNum = bottoms[i-1];
            // pick top, stay top
            if (dp[i-1][topNum][0] < INT_MAX) dp[i][topNum][0] = min(dp[i-1][topNum][0], dp[i][topNum][0]);

            // pick top, switch to bottom
            if (dp[i-1][topNum][1] < INT_MAX) dp[i][topNum][1] = min(1 + dp[i-1][topNum][1], dp[i][topNum][1]);

            // pick bottom, stay bottom
            if (dp[i-1][bottomNum][1] < INT_MAX) dp[i][bottomNum][1] = min(dp[i-1][bottomNum][1], dp[i][bottomNum][1]);            

            // pick bottom, switch top
            if (dp[i-1][bottomNum][0] < INT_MAX) dp[i][bottomNum][0] = min(1 + dp[i-1][bottomNum][0], dp[i][bottomNum][0]);   
        }

        int res = min({dp[N][tops.back()][0], dp[N][tops.back()][1], dp[N][bottoms.back()][0], dp[N][bottoms.back()][1]});

        return res<INT_MAX?res:-1;
    }
};



// greedy
class Solution {
public:
    int count(int x, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;

        for (int i=0; i<tops.size(); i++) {
            if (tops[i] != x && bottoms[i] != x) {
                return -1;
            } else if (tops[i] != x) {
                rotateTop += 1;
            } else if (bottoms[i] != x) {
                rotateBottom += 1;
            }
        }

        return min(rotateTop, rotateBottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int res = count(tops[0], tops, bottoms);
        if (res != -1 || bottoms[0] == tops[0]) return res;  // note this line, clever
        return count(bottoms[0], tops, bottoms);
    }
};