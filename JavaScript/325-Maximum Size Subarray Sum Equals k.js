/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxSubArrayLen = function(nums, k) {
    let hmap = new Map();
    hmap.set(0,-1);
    let res = 0, sum = 0;
    for (let i=0; i<nums.length; i++){
        sum += nums[i];
        if (!hmap.has(sum)){
            hmap.set(sum, i);
        }
        if (hmap.has(sum-k)){
            res = Math.max(res, i-hmap.get(sum-k));
        }
    }
    return res;
};