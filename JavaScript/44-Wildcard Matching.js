/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let dp = Array.from(Array(s.length+1), () => new Array(p.length+1).fill(false));
    dp[0][0] = true;
    for (let j=1; j < p.length+1; j++){
        if (p[j-1] ==='*') dp[0][j] = dp[0][j-1];
        else dp[0][j] = false;
    }
    for (let i=1; i < s.length+1; i++){
        for (let j=1; j< p.length+1; j++){
            if (s[i-1] === p[j-1] || p[j-1] ==='?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if (p[j-1] === '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
                
        }
    }
    return dp[s.length][p.length];
};