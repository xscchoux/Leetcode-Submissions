/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    const row = t.length, col = s.length;
    let dp = new Array(row+1).fill().map(()=> new Array(col+1).fill(0));
    
    // edge case, set all dp[0][c] = 1 to match
    for (let c=0; c<=col; c++){
        dp[0][c] = 1;
    }
    
    for (let r=1; r<=row; r++){
        for (let c=1; c<=col; c++){
            if (s[c-1] === t[r-1]){
                dp[r][c] = dp[r-1][c-1] + dp[r][c-1];
            }else{
                dp[r][c] = dp[r][c-1];
            }
        }
    }
    
    return dp[row][col];
};