class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy && t == 1){
            return false;
        }
        
        int diffY = abs(fy-sy);
        int diffX = abs(fx-sx);
        
        return t >= max(diffX, diffY);
        
    }
};