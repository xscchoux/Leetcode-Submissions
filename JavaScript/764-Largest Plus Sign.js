/**
 * @param {number} n
 * @param {number[][]} mines
 * @return {number}
 */
var orderOfLargestPlusSign = function(n, mines) {
    let dp = new Array(n).fill().map( ()=> new Array(n).fill(Number.POSITIVE_INFINITY));
    for (let [r, c] of mines){
        dp[r][c] = 0;
    }
    
    for (let r=0; r<n; r++){
        let reverseC, lCount=0, rCount=0;
        for (let c=0; c<n; c++){
            reverseC = n-1-c;
            if (dp[r][c] !== 0){
                lCount++;
                dp[r][c] = Math.min(dp[r][c], lCount)
            }else{
                lCount=0;
            }
            
            if (dp[r][reverseC] !== 0){
                rCount++;
                dp[r][reverseC] = Math.min(dp[r][reverseC], rCount);
            }else{
                rCount=0;
            }   
        }
    }
    
    for (let c=0; c<n; c++){
        let reverseR, uCount=0, dCount=0;
        for (let r=0; r<n; r++){
            reverseR = n-1-r;
            if (dp[r][c] !== 0){
                uCount++;
                dp[r][c] = Math.min(dp[r][c], uCount)
            }else{
                uCount=0;
            }
            if (dp[reverseR][c] !== 0){
                dCount++;
                dp[reverseR][c] = Math.min(dp[reverseR][c], dCount);
            }else{
                dCount=0;
            }   
        }
    }
    
    let res = 0;
    for (let r=0; r<n; r++){
        for (let c=0; c<n; c++){
            if (dp[r][c] == 0) continue;
            res = Math.max(res, dp[r][c]);
        }
    }
    
    return res;
};