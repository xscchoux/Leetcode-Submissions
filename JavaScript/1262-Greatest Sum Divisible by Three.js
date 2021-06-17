/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSumDivThree = function(nums) {
    
    let dp = new Array(3).fill(0);
    
    for (let num of nums){
        let prev_dp = [...dp];
        for (let i=0; i<3; i++){
            dp[(prev_dp[i]+num)%3] = Math.max(prev_dp[i] + num ,dp[(prev_dp[i]+num)%3] )
        }
    }
    return dp[0];
};