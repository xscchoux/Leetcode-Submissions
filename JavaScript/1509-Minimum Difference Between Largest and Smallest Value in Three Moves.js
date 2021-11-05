/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function(nums) {
    const N = nums.length;
    if (N<=4) return 0;
    let res = Number.POSITIVE_INFINITY;
    nums.sort(function(a,b){return a-b;});
    for (let i=0; i<4; i++){
        res = Math.min(res, nums[N-4+i]-nums[i]);
    }
    return res;
};