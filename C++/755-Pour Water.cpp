class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int N = heights.size();
        while (volume-- > 0) {
            int currLevel = heights[k];
            int minLeftLevel = currLevel, leftIdx = k;

            for (int left=k-1; left>=0; left--) {
                if (heights[left] < minLeftLevel) {
                    minLeftLevel = heights[left];
                    leftIdx = left;
                }
                if (heights[left] > heights[left+1]) break;
            }
            if (leftIdx != k) {
                heights[leftIdx]++;
                continue;
            }

            int minRightLevel = currLevel, rightIdx = k; 
            for (int right=k+1; right<N; right++) {
                if (heights[right] < minRightLevel) {
                    minRightLevel = heights[right];
                    rightIdx = right;
                }
                if (heights[right-1] < heights[right]) break;
            }
            if (rightIdx != k) {
                heights[rightIdx]++;
                continue;
            }
            heights[k]++;
        }

        return heights;
    }
};