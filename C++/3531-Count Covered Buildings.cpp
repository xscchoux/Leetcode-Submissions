class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> xMap, yMap;
        int res = 0;

        for (auto &b:buildings) {
            int x = b[0], y = b[1];
            xMap[x].push_back(y);
            yMap[y].push_back(x); 
        }

        for (auto &[k, v]:xMap) {
            sort(begin(v), end(v));
        }

        for (auto &[k, v]:yMap) {
            sort(begin(v), end(v));
        }

        for (auto &b:buildings) {
            int x = b[0], y = b[1];
            if (xMap[x].size() >= 3 && xMap[x].back() != y && xMap[x].front() != y && yMap[y].size() >= 3 && yMap[y].back() != x && yMap[y].front() != x) {
                res++;
            }
        }

        return res;
    }
};


// Much faster
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minX(n+1, n+1), maxX(n+1, 0), minY(n+1, n+1), maxY(n+1, 0);
        int res = 0;
        
        for (auto &b:buildings) {
            int x = b[0], y = b[1];
            minX[y] = min(minX[y], x);
            minY[x] = min(minY[x], y);
            maxX[y] = max(maxX[y], x);
            maxY[x] = max(maxY[x], y);
        }

        for (auto &b:buildings) {
            int x = b[0], y = b[1];
            if (x > minX[y] && x < maxX[y] && y > minY[x] && y < maxY[x]) {
                res++;
            }
        }

        return res;
    }
};