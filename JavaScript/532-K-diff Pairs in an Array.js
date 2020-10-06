/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
    let numSet = new Set();
    let res = new Set()
    
    nums.sort(function(a,b){return a-b;})
    
    for (let i=0; i<nums.length; i++){
        if (numSet.has(nums[i]-k)) res.add((nums[i],nums[i]-k));
        numSet.add(nums[i])
    }
    
    return res.size;
};