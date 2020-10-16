/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    let left = 0, right = nums.length-1;
    while (left+1 < right){
        mid = left + Math.floor((right-left)/2);
        console.log(mid)
        if (mid % 2 === 1){
            if (nums[mid] === nums[mid-1]){
                left = mid;
            }
            else {
                right = mid;
            }
        }
        else{
            if (nums[mid] === nums[mid+1]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
    }
    return left % 2 ? nums[right]:nums[left];
};