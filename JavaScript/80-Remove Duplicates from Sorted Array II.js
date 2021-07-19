/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let i = 0
    for (let num of nums){
        if (i < 2 || num > nums[i-2]){
            nums[i] = num;
            i++;
        }
    }
    return i;
};