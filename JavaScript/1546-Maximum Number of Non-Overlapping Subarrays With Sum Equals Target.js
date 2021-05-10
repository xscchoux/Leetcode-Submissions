/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var maxNonOverlapping = function(nums, target) {
    let dp = new Map();
    let runningSum = 0, res = 0;
    dp.set(0, 0);
    
    for (let num of nums){
        runningSum += num;
        if (dp.has(runningSum-target)){
            res = Math.max(res, dp.get(runningSum-target) + 1);
        }
        dp.set(runningSum, res);
    }
    return res;
};