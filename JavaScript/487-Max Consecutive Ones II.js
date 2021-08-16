/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let left = 0, numZero = 0, res = 0;
    for (let i=0; i<nums.length; i++){
        if (nums[i] === 0) numZero++;
        if (numZero === 2){
            res = Math.max(res, i-1-left+1);
            while (numZero === 2){
                numZero -= 1-nums[left];
                left++;
            }
        }
    }
    res = Math.max(res, nums.length-1-left+1);
    return res;
};