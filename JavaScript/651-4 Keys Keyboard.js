/**
 * @param {number} n
 * @return {number}
 */
var maxA = function(n) {
    dp = Array(n+1).fill().map((v,i)=>i);
    
    for (let i=3; i<=n; i++){
        for (let j=2; j<=i-3; j++){
            dp[i] = Math.max(dp[i], dp[j]*(i-j-1));
        }
    }
    return dp[n];
};