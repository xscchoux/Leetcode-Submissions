/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let lenS = s.length, lenP = p.length;
    let dp = new Array(lenS+1).fill(0).map(()=>new Array(lenP+1).fill(false));
    
    dp[0][0] = true;
    
    for (let j=1; j < lenP+1; j++){
        if ( p[j-1] === '*'){
            dp[0][j] = dp[0][j-2];
        }
    }
    
    for (let i=1; i < lenS+1; i++){
        for (let j=1; j < lenP+1; j++){
            if (s[i-1] === p[j-1] || p[j-1] === '.'){
                dp[i][j] = dp[i-1][j-1];
            }else if (p[j-1] === '*'){
                dp[i][j] = dp[i][j-2];
                if (p[j-2] === s[i-1] || p[j-2] === '.'){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }else{
                dp[i][j] = false;
            }
        }
    }
    
    return dp[lenS][lenP];
};