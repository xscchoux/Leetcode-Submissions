/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var maxSumAfterPartitioning = function(arr, k) {
    const N = arr.length;
    let dp = new Array(N+1).fill(0);
    
    for (i=0; i<arr.length; i++){
        let currMax = arr[i];
        const limit = Math.min(i+1, k);
        for (let j=0; j<limit; j++){
            currMax = Math.max(currMax, arr[i-j]);
            dp[i+1] = Math.max(dp[i+1], dp[i-j] + currMax*(j+1));
        }
    }
    return dp[N];
};