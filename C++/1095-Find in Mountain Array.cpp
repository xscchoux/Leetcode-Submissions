/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &A) {
        int left = 0, right = A.length()-1;
        int peak;
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (A.get(mid) < A.get(mid+1))
                left = mid;
            else
                right = mid;
        }
        
        peak = left;
        
        left = 0;
        right = peak;
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (A.get(mid) <= target)
                left = mid;
            else
                right = mid;
        }        
        if (A.get(left) == target) return left;
        if (A.get(right) == target) return right;
        
        
        left = peak+1;
        right = A.length()-1;
        while (left + 1 < right){
            int mid = left + (right-left)/2;
            if (A.get(mid) >= target)
                left = mid;
            else
                right = mid;
        }        
        if (A.get(left) == target) return left;
        if (A.get(right) == target) return right;        
        
        return -1;
    }
};