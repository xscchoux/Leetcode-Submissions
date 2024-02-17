class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int N = heights.size();
        int remain = 0;
        
        for (int i=1; i<N; i++) {
            if (heights[i]-heights[i-1] > 0) {
                pq.push(heights[i]-heights[i-1]);
                if (pq.size() > ladders) {
                    remain += pq.top();
                    pq.pop();
                    if (remain > bricks) return i-1;
                }
            }
        }
        return N-1;
    }
};