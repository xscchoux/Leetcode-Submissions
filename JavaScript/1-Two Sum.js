/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const hmap = new Map();
    for (let i=0; i<nums.length; i++){
        if (hmap.has(target-nums[i])){
            return [hmap.get(target-nums[i]),i]
        }
        hmap.set(nums[i],i);
    }
    
};