/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let localmax = 0;
    let globalmax = Number.NEGATIVE_INFINITY;
    
    for (let num of nums){
        if (localmax > 0) localmax += num;
        else{
            localmax = num;
        }
        if (localmax > globalmax){
            globalmax = localmax;
        }
    }
    return globalmax;
};