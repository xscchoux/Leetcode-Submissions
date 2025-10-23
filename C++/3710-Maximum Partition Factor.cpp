class Solution {
public:
    int N;
    bool isOK(vector<vector<int>>& points, int dist) {
        vector<vector<int>> graph(N);
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]) < dist) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
       
        // check if the graph is bipartite
        vector<int> color(N, -1); // should be 0 or 1 if visited

        for (int i=0; i<N; i++) {
            if (color[i] == -1) {
                // BFS
                // any edge should connect to nodes of different colors
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int idx = q.front();
                    q.pop();
                    int nxtColor = 1 - color[idx];
                    for (int nxt:graph[idx]) {
                        if (color[nxt] != -1) {
                            if (color[nxt] != nxtColor) return false;
                        } else {
                            color[nxt] = nxtColor;
                            q.push(nxt);
                        }
                    }
                }
            }
        }

        return true;
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        this->N = points.size();
        if (N == 2) return 0;

        int maxD = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                maxD = max(maxD, abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
            }
        }

        int left = 1, right = maxD;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (isOK(points, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isOK(points, right)) {
            return right;
        } else if (isOK(points, left)) {
            return left;
        } else {
            return 0;
        }

    }
};