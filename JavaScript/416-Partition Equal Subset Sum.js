/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    let sum = nums.reduce((a,b)=>a+b, 0);
    if (sum%2){
        return false;
    }
    
    let subsetSum = sum/2;
    
    let dp = new Array(subsetSum+1).fill(false);
    dp[0] = true;
    for (let num of nums){
        for (let j = subsetSum; j>=num; j--){
                dp[j] |= dp[j-num];
        }    
    }
    return dp[dp.length-1];
};