class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();
        vector<int> indegree(N);
        vector<vector<int>> graph(N), cnt(N, vector<int>(26, 0));

        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i=0; i<N; i++) {
            if (indegree[i] == 0) {
                cnt[i][colors[i]-'a']++;
                q.push(i);
            }
        }

        if (q.empty()) return -1;

        int res = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            res = max(res, cnt[curr][colors[curr]-'a']);

            for (int nxt:graph[curr]) {
                indegree[nxt]--;
                for (int i=0; i<26; i++) {
                    if (i != (colors[nxt] - 'a') ) {
                        cnt[nxt][i] = max(cnt[nxt][i], cnt[curr][i]);
                    } else {
                        cnt[nxt][i] = max(cnt[nxt][i], cnt[curr][i] + 1);
                    }
                }
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        for (int i=0; i<N; i++) {
            if (indegree[i] != 0) return -1;
        }

        return res;
    }
};