/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let dp = new Array(n+2).fill(0);
    dp[1] = 1;
    for (let i=2; i<dp.length; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[dp.length-1]
};