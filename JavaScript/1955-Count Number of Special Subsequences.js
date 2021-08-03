/**
 * @param {number[]} nums
 * @return {number}
 */
var countSpecialSubsequences = function(nums) {
    let dp = new Array(3).fill(0);
    const kMod = Math.pow(10,9) + 7;
    for (let num of nums){
        if (num === 0){
            dp[0] = (2*dp[0] + 1)%kMod;
        }else{
            dp[num] = (2*dp[num] + dp[num-1])%kMod;
        }
    }
    return dp[2];
};