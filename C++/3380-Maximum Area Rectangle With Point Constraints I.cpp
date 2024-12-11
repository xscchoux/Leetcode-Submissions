// first AC, very inefficient
class Solution {
public:
    int getRectangle(vector<vector<int>>& points, int i, int j, int k, int l) {
        unordered_map<int, vector<int>> hmap;
        int x1=100, x2=0;
        hmap[points[i][0]].push_back(points[i][1]);
        hmap[points[j][0]].push_back(points[j][1]);
        hmap[points[k][0]].push_back(points[k][1]);
        hmap[points[l][0]].push_back(points[l][1]);
        if (hmap.size() != 2) return -1;
        int length = -1;
        for (auto &[k, v]:hmap) {
            if (v.size() != 2) return -1;
            if (length == -1) length = abs(v[0]-v[1]);
            else {
                if (length != abs(v[0]-v[1])) return -1;
            }
            x1 = min(x1, k);
            x2 = max(x2, k);
        }
        
        int y1=100, y2=0;
        unordered_map<int, vector<int>> hmap2;
        hmap2[points[i][1]].push_back(points[i][0]);
        hmap2[points[j][1]].push_back(points[j][0]);
        hmap2[points[k][1]].push_back(points[k][0]);
        hmap2[points[l][1]].push_back(points[l][0]);
        if (hmap2.size() != 2) return -1;
        int length2 = -1;
        for (auto &[k, v]:hmap2) {
            if (v.size() != 2) return -1;
            if (length2 == -1) length2 = abs(v[0]-v[1]);
            else {
                if (length2 != abs(v[0]-v[1])) return -1;
            }
            y1 = min(y1, k);
            y2 = max(y2, k);
        }

        for (int p=0; p<points.size(); p++) {
            if (p!=i && p!=j && p!=k && p!=l && (points[p][0]>=x1 && points[p][0]<=x2 && points[p][1]>=y1 && points[p][1]<=y2)) {
                return -1;
            }
        }

        return length*length2;
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int N = points.size();
        int res = -1;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                for (int k=j+1; k<N; k++) {
                    for (int l=k+1; l<N; l++) {
                        res = max(res, getRectangle(points, i, j, k, l));
                    }
                }
            }
        }
        return res;
    }
};



// straightforward, 0ms
class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int N = points.size();
        sort(begin(points), end(points));
        int res = -1;

        // four edges correspond to the four if statements
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) if (points[i][0] == points[j][0]) {
                for (int u=j+1; u<N; u++) if (points[u][1] == points[i][1]) {
                    for (int v=u+1; v<N; v++) if (points[u][0] == points[v][0] && points[v][1] == points[j][1]) {
                        bool isOK = true;
                        for (int k=0; k<N; k++) {
                            if (k!=i && k!=j && k!=u && k!=v && points[k][0]>=points[i][0] && points[k][0] <= points[u][0] && points[k][1]>=points[i][1] && points[k][1]<=points[j][1]) {
                                isOK = false;
                                break;
                            }
                        }
                        if (isOK) {
                            res = max(res, (points[u][0]-points[i][0])*(points[j][1]-points[i][1]));
                        }
                    }
                }
            }
        }
        
        return res;
    }
};