class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int dist = 0;
        int res = INT_MAX;
        int toChange = INT_MAX;
        for (vector<int> nut:nuts){
            dist += (abs(nut[0]-tree[0]) + abs(nut[1]-tree[1]))*2;
            toChange = min(toChange, (abs(nut[0]-squirrel[0]) + abs(nut[1]-squirrel[1]))-(abs(nut[0]-tree[0]) + abs(nut[1]-tree[1])));
        }

        return dist + toChange;
    }
};