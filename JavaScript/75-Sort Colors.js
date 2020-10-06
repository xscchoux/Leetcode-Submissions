/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let p0 = 0; p1 = 0; p2 = nums.length-1;
    while (p1 <= p2){
        if (nums[p1] === 2){
            [nums[p1], nums[p2]] = [nums[p2], nums[p1]];
            --p2;
        } else if (nums[p1] === 1){
            ++p1;
        } else{
            [nums[p1], nums[p0]] = [nums[p0], nums[p1]];
            ++p0;
            ++p1;
        }
    }
};