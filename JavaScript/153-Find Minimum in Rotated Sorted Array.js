/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let left = 0, right = nums.length-1;
    while (left + 1 < right){
        mid = left + Math.floor((right-left)/2);
        if (nums[mid] <= nums[right]){
            right = mid;
        }else{
            left = mid;
        }
    }
    return Math.min(nums[left], nums[right]);
};