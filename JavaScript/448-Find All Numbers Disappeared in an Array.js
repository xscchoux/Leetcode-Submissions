/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    for (let i=0; i<nums.length; i++){
        index = Math.abs(nums[i]) - 1;
        nums[index] = -Math.abs(nums[index]);
    }
    let res = [];
    for (let j=0; j<nums.length; j++){
        if (nums[j]>0) res.push(j+1);
    }
    return res;
};