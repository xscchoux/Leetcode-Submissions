class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        // Both should be on black cells or on white cells
        int deltaY = source[0] - target[0], deltaX = source[1] - target[1];

        if ((abs(deltaY) + abs(deltaX))&1) return -1;

        if (abs(deltaY) == abs(deltaX)) return 1;
        
        return 2;
    }
};