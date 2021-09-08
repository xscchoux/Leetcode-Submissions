/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var smallestRangeII = function(nums, k) {
    nums.sort(function(a,b){return a-b;})
    const N = nums.length;
    let res = nums[N-1] - nums[0];
    
    for (let i=0; i<N-1; i++){
        let mx = Math.max(nums[i]+k, nums[N-1]-k);
        let mn = Math.min(nums[0]+k, nums[i+1]-k);
        res = Math.min(res, mx-mn);
    }
    return res;
};