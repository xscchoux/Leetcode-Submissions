/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let numSet = new Set(nums);
    let res = 0
    let length = 0;
    
    for (let num of nums){
        if (numSet.has(num-1)) continue;
        length = 0;
        while (numSet.has(num)){
            num += 1;
            length += 1;
        }
        res = Math.max(res, length);
    }
    return res;
};