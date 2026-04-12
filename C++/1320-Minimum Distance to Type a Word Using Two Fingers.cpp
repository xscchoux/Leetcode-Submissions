// First AC, lengthy and slow
int dist[26][26] = {0};
bool filled = false;
void create() {
    int row = 5, col = 6;
    vector<vector<char>> mat(row, vector<char>(col, '#'));
    char curr = 'A';

    map<char, pair<int, int>> hmap;

    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            mat[r][c] = curr;
            hmap[curr] = {r, c};
            curr++;
            if (curr >　'Z') break;
        }
        if (curr > 'Z') break;
    }

    for (char c1 = 'A'; c1 <= 'Z'; c1++) {
        for (char c2 = c1+1; c2 <= 'Z'; c2++) {
            int distance = abs(hmap[c1].first - hmap[c2].first) + abs(hmap[c1].second - hmap[c2].second);
            dist[c1-'A'][c2-'A'] = distance;
            dist[c2-'A'][c1-'A'] = distance;
        }
    }
}


class Solution {
public:
    int N;
    Solution() {
        if (!filled) {
            create();
        }
    }
    int dfs(int pos1, int pos2, int prePos, string& word, vector<vector<vector<int>>>& dp) {
        int curr;
        if (prePos == 0) {
            curr = 0;
        } else {
            if (prePos == 1) {
                curr = pos1+1;
            } else {
                curr = pos2+1;
            }
        }
        if (curr == N) {
            return 0;
        }

        if (dp[pos1][pos2][prePos] != INT_MAX) return dp[pos1][pos2][prePos];

        int tot = INT_MAX;
        // use pos1
        tot = (pos1 == N?0:dist[word[pos1]-'A'][word[curr]-'A']) + dfs(curr, pos2, 1, word, dp);

        // use pos2
        tot = min(tot, (pos2 == N?0:dist[word[pos2]-'A'][word[curr]-'A']) + dfs(pos1, curr, 2, word, dp));     

        return dp[pos1][pos2][prePos] = tot;
    }
    int minimumDistance(string word) {

        this->N = word.size();
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(3, INT_MAX)));   // dp[position of finger 1][positsion of finger 2][no. of last finger]

        int pos1 = N, pos2 = N, prePos = 0;
        int res = dfs(pos1, pos2, prePos, word, dp);

        return res;
    }
};



class Solution {
public:
    int dp[301][27][27];  // dp[index][character of finger 1][character of finger 2]
    int getDist(int p, int q) {
        if (p == 26) return 0;
        return abs(p/6 - q/6) + abs(p%6 - q%6);
    }
    int dfs(int idx, int f1, int f2, string& word) {
        if (idx == word.size()) {
            return 0;
        }
        if (dp[idx][f1][f2] != -1) return dp[idx][f1][f2];

        int target = word[idx] - 'A';

        // move finger 1
        int res = getDist(f1, target) + dfs(idx+1, target, f2, word);

        // move finger 2
        res = min(res, getDist(f2, target) + dfs(idx+1, f1, target, word));
        
        return dp[idx][f1][f2] = res;
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));

        return dfs(0, 26, 26, word);  // set "no character" to be 26 for both fingers
    }
};