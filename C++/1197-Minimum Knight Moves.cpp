class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<pair<pair<int, int>, int>> queue;  // {{x, y}, step}
        queue.push({{0,0},0});
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        vector<vector<int>> direction = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        
        x = abs(x);
        y = abs(y);
        
        while (!queue.empty()){
            pair<pair<int, int>, int> curr = queue.front();
            queue.pop();
            int currX = curr.first.first;
            int currY = curr.first.second;
            int step = curr.second;
            // cout << currX << currY << step << endl;
            if (currX == x && currY == y) return step;
            
            for (vector<int> diff:direction){
                int dx = diff[0], dy = diff[1];
                int nxtX = currX + dx;
                int nxtY = currY + dy;
                // cout << nxtX << nxtY << step << endl;
                if (nxtX >= -2 && nxtX <= x+2 && nxtY >= -2 && nxtY <= y+2){
                    if (visited.find({nxtX, nxtY}) == visited.end()){
                        visited.insert({nxtX, nxtY});
                        queue.push({{nxtX, nxtY}, step+1});
                    }
                }
            }
        }
        return 0;
    }
};