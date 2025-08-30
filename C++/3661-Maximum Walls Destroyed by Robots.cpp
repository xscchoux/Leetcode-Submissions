using PII = pair<int, int>;
class Solution {
public:
    int count(vector<int>& walls, int left, int right) {
        if (left > right) return 0;
        auto it1 = lower_bound(begin(walls), end(walls), left);
        auto it2 = upper_bound(begin(walls), end(walls), right);

        return it2-it1;
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int N = robots.size();
        vector<PII> pos;
        for (int i=0; i<N; i++) {
            pos.push_back({robots[i], distance[i]});
        }

        sort(begin(pos), end(pos));
        sort(begin(walls), end(walls));
        pos.push_back({1e9+1, 0});  // we need this for pos[i+1]

        vector<vector<int>> dp(N, vector<int>(2, 0)); // dp[i][0]:maximum walls destroyed from 0~i if move left at i
                                                      // dp[i][1]:maximum walls destroyed from 0~i if move right at i
        
        dp[0][0] = count(walls, max(0, pos[0].first-pos[0].second), pos[0].first);
        if (N > 1) {
            dp[0][1] = count(walls, pos[0].first, min(pos[0].first + pos[0].second, pos[1].first-1));
        } else {
            dp[0][1] = count(walls, pos[0].first, pos[0].first + pos[0].second);
        }


        for (int i=1; i<N; i++) {
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + count(walls, pos[i].first, min(pos[i].first + pos[i].second, pos[i+1].first-1));
            dp[i][0] = dp[i-1][0] + count(walls, max(pos[i].first-pos[i].second, pos[i-1].first+1), pos[i].first);

            // substract the overlapped
            dp[i][0] = max(dp[i][0], dp[i-1][1] + count(walls, max(pos[i].first-pos[i].second, pos[i-1].first+1), pos[i].first) - count(walls, max(pos[i].first-pos[i].second, pos[i-1].first+1), min(pos[i-1].first + pos[i-1].second, pos[i].first-1) ));

        }

        return max(dp[N-1][0], dp[N-1][1]);
    }
};