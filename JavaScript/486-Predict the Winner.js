/**
 * @param {number[]} nums
 * @return {boolean}
 */
var PredictTheWinner = function(nums) {
    let dp = [...nums], N = nums.length;
    
    for (let length = 2; length <= N; length++){
        for (let end = N-1; end >= length-1; end--){
            let start = end-length+1;
            dp[end] = Math.max(nums[end]-dp[end-1], nums[start]-dp[end]);
        }
    }
    return dp[N-1] >= 0;
};