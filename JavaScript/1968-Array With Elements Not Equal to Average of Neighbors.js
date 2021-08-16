/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    for (let i=1; i<nums.length-1; i++){
        if ((nums[i] > nums[i-1])^(nums[i] > nums[i+1])){
            [nums[i], nums[i+1]] = [nums[i+1], nums[i]];
        }
    }
    return nums;
};