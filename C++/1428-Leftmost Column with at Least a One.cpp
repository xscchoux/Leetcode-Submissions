/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int row = dim[0], col = dim[1];
        int leftMost = col+1;
        for (int r=0; r<row; r++) {
            int left = 0, right = col-1;
            while ( left + 1 < right) {
                int mid = left + (right-left)/2;
                if (binaryMatrix.get(r, mid) > 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            if (binaryMatrix.get(r, left) > 0) {
                leftMost = min(leftMost, left);
            }
            else if (binaryMatrix.get(r, right) > 0) {
                leftMost = min(leftMost, right);
            }
        }
        
        return leftMost==col+1?-1:leftMost;
    }
};