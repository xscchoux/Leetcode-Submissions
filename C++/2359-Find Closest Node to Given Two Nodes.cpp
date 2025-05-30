// First AC
class Solution {
public:
    void dfs(int curr, int d, vector<int>& edges, unordered_map<int, int>& hmap) {
        hmap[curr] = d;

        if (edges[curr] == -1 || hmap.contains(edges[curr])) return;

        dfs(edges[curr], d+1, edges, hmap);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, int> hmap1, hmap2;

        dfs(node1, 0, edges, hmap1);
        dfs(node2, 0, edges, hmap2);

        int maxDist = INT_MAX, res = INT_MAX;
        for (auto &[k, v]:hmap1) {
            if (hmap2.contains(k)) {
                int currMaxDist = max(v, hmap2[k]);
                if (currMaxDist < maxDist) {
                    maxDist = currMaxDist;
                    res = k;
                } else if (currMaxDist == maxDist) {
                    res = min(res, k);
                }
            }
        }        

        return res==INT_MAX?-1:res;
    }
};

// Better
class Solution {
public:
    void dfs(int curr, int d, vector<int>& edges, vector<int>& dist) {
        dist[curr] = d;

        if (edges[curr] == -1 || dist[edges[curr]] != -1 ) return;

        dfs(edges[curr], d+1, edges, dist);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N = edges.size();
        vector<int> dist1(N, -1);
        vector<bool> visited(N, false);
        dfs(node1, 0, edges, dist1);

        int maxDist = INT_MAX, res = INT_MAX, curr = node2, dist = 0;
        while (curr != -1 && !visited[curr]) {
            visited[curr] = true;
            if (dist1[curr] != -1) {
                int currMaxDist = max(dist, dist1[curr]);
                if (currMaxDist < maxDist) {
                    maxDist = currMaxDist;
                    res = curr;
                } else if (currMaxDist == maxDist) {
                    res = min(res, curr);
                }
            }
            dist++;
            curr = edges[curr];
        }

        return res==INT_MAX?-1:res;
    }
};