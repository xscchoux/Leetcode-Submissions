/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
    for (let i=0; i<nums.length-1; i++){
        if(i%2^(nums[i]>nums[i+1])){
            [nums[i], nums[i+1]] = [nums[i+1], nums[i]];
        }
    }
};