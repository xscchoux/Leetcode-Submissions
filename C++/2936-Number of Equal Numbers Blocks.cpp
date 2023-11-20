/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
using LL = long long;
class Solution {
public:
    LL findRight(BigArray* nums, LL left){
        LL right = nums->size()-1;
        while (left + 1 < right){
            LL mid = left + (right-left)/2;
            if (nums->at(left) == nums->at(mid)){
                left = mid;
            } else{
                right = mid;
            }
        }
        if (nums->at(left) == nums->at(right)){
            return right + 1;
        }else{
            return left + 1;
        }
    }
    
    int countBlocks(BigArray* nums) {
        LL right = nums->size()-1;
        LL start = 0;
        int count = 0;
        while (start <= right){
            start = findRight(nums, start);
            count++;
        }
        return count;
    }
};