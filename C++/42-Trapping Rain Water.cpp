class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i=0; i<height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int prevH = height[stk.top()];
                stk.pop();
                if (stk.empty()) break; 
                int w = i - stk.top() - 1;
                int h = min(height[i], height[stk.top()]) - prevH;
                res += w*h;
            }
            stk.push(i);
        }
        return res;
    }
};