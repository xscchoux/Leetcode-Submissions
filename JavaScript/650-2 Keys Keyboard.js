/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
    // dp
    let dp = Array(n+1).fill().map((v,i)=>i);
    dp[1] = 0;
    for (let i=2; i<=n; i++){
        for (let j=2; j<= ((i/2)|0); j++){
            if (i%j === 0){
                dp[i] = Math.min(dp[i], dp[j] + i/j);
            }
        }
    }
    return dp[n];
    
    //prime factorization
    
    let res = 0, d = 2;
    
    while (n > 1){
        while (n%d === 0){
            res += d;
            n = n/d;
        }
        d += 1;
    }
    
    return res;
};