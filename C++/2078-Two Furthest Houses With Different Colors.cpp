// The interval we seek must have one endpoint that is also an endpoint of colors
// Use two pointers at both ends and move simultaneously
// Only need to check half of `colors`
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int N = colors.size();
        for (int i=0; i<N/2+1; i++) {
            if (colors[N-1] != colors[i] || colors[N-i-1] != colors[0]) {
                return N-i-1;
            }
        }
        return 0;

    }
};