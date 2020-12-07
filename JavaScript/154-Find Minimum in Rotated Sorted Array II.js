/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let left = 0, right = nums.length-1;
    
    while (left + 1 < right){
        let mid = left + ((right - left)>>1);
        if (nums[mid] > nums[right]){
            left = mid;
        }else if (nums[mid] < nums[left]){
            right = mid;
        }else{
            right--;
        }
    }
    return Math.min(nums[left], nums[right]);
};