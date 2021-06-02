/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    nums.unshift(Number.NEGATIVE_INFINITY);
    nums.push(Number.NEGATIVE_INFINITY);
    
    let left = 1, right = nums.length-2;
    while (left + 1 < right){
        let mid = left + right >> 1;
        if (nums[mid] < nums[mid+1]){
            left = mid;
        }else if (nums[mid] < nums[mid-1]){
            right = mid;
        }else{
            return mid-1;
        }
    }
    
    if (nums[left] < nums[right]){
        return right-1;
    }else{
        return left - 1;
    }
    
};