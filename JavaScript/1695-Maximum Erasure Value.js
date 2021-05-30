/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
    let left = 0, currSum = 0, res = 0;
    let used = new Set();
    
    for (let i=0; i<nums.length; i++){
        if (used.has(nums[i])){
            res = Math.max(res, currSum);
            while (used.has(nums[i])){
                used.delete(nums[left]);
                currSum -= nums[left];
                left += 1;                
            }
        }
        currSum += nums[i];
        used.add(nums[i]);
    }
    
    res = Math.max(res, currSum);
    return res;
};