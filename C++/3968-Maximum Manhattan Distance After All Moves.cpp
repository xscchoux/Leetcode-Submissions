class Solution {
public:
    int maxDistance(string moves) {
        int H = 0, V = 0, B = 0;

        for (char c:moves) {
            if (c == 'U') {
                V++;
            } else if (c == 'D') {
                V--;
            } else if (c == 'L') {
                H--;
            } else if (c == 'R') {
                H++;
            } else {
                B++;
            }
        }

        return abs(V) + abs(H) + B;

    }
};