/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let farthest = 0;
    for (let i=0; i<nums.length; i++){
        if (i>farthest) return false;
        if (i+nums[i]>=nums.length-1){
            return true;
        }
        if (i+nums[i]>farthest){
            farthest = i+nums[i];
        }
    }
    return false;
};