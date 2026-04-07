class Robot {
public:
    int posX = 0, posY = 0;
    int row, col;
    int perimeter = 0;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // east, north, west, south
    int dirIdx = 0;

    Robot(int width, int height) {
        row = height;
        col = width;
        perimeter = 2*row + 2*col - 4;
    }
    
    void step(int num) {
        if (num == 0) return;
        if (num%perimeter  == 0) num = perimeter;
        else num = num%perimeter;
        while (num > 0) {
            while (!(posX + dir[dirIdx].first >= 0 && posX + dir[dirIdx].first < col) || !(posY + dir[dirIdx].second >= 0 && posY + dir[dirIdx].second < row)) {
                dirIdx = (dirIdx + 1)%4;
            }
            posX += dir[dirIdx].first;
            posY += dir[dirIdx].second;
            num--;
        }
    }
    
    vector<int> getPos() {
        return {posX, posY};
    }
    
    string getDir() {
        if (dirIdx == 0) {
            return "East";
        } else if (dirIdx == 1) {
            return "North";
        } else if (dirIdx == 2) {
            return "West";
        } else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */