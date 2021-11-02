/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    nums.sort(function(a,b){return a-b;});
    
    const median = nums[(nums.length/2)|0];
    let res = 0;
    
    for (let num of nums){
        res += Math.abs(num-median);    
    }
    return res;
};