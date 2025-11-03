class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        priority_queue<int> pq;

        for (int r=0; r<sideLength; r++) {
            for (int c=0; c<sideLength; c++) {
                // set (r, c) to 1
                int colCnt = 1 + (width-1-c)/sideLength;
                int rowCnt = 1 + (height-1-r)/sideLength;
                pq.push(rowCnt*colCnt);
            }
        }
        int res = 0;
        while (maxOnes-- > 0) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};