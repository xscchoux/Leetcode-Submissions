// First AC
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        vector<int> leftMax(N, 0), rightMax(N, 0);

        for (int i=0; i<N; i++) {
            if (i == 0) {
                leftMax[i] = height[i];
            } else {
                leftMax[i] = max(height[i], leftMax[i-1]);
            }
        }

        for (int i=N-1; i>=0; i--) {
            if (i == N-1) {
                rightMax[i] = height[i];
            } else {
                rightMax[i] = max(height[i], rightMax[i+1]);
            }
        }

        int left = 0, right = N-1;
        int res = 0;
        while (left < right) {
            res = max(res, (right-left)*min(rightMax[right], leftMax[left]));
            if (leftMax[left] < rightMax[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};


// Better
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        
        int left = 0, right = N-1;
        int res = 0;
        while (left < right) {
            res = max(res, (right-left)*min(height[right], height[left]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};