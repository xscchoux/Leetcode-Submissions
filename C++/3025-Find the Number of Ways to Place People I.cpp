// First AC, O(N^3)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](auto &a, auto &b) {
            return (a[0] < b[0])||(a[0] == b[0] && a[1] > b[1]);
        });
        
        int res = 0;

        for (int i=0; i<points.size(); i++) {
            vector<int> yPos;
            int Y = points[i][1];
            for (int j=i+1; j<points.size(); j++) {
                int currY = points[j][1];
                if (currY > Y) continue;
                bool found = false;
                for (int yy:yPos) {
                    if (currY <= Y && (yy<=Y && yy>=currY)) {
                        found = true;
                        break;
                    }
                }
                if (!found) res++; 
                yPos.push_back(currY);
            }
        }

        return res;
    }
};


// Better, O(N^2)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](auto &a, auto &b) {
            return (a[0] < b[0])||(a[0] == b[0] && a[1] > b[1]);
        });
        
        int res = 0;

        for (int i=0; i<points.size(); i++) {
            int Y = points[i][1], lastY = -1;
            for (int j=i+1; j<points.size(); j++) {
                int currY = points[j][1];
                if (currY > Y) continue;
                if (currY > lastY) {
                    lastY = currY;
                    res++;
                }
            }
        }

        return res;
    }
};