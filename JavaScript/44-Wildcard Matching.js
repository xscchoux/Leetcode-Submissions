/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */

// DP
// Time: O(SP), Space:O(SP)

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


// backtracking
// Time: O(SP), Space:O(1)

var isMatch = function(s, p) {
    let i = 0, j = 0;
    let star = -1, istar = 0;
    
    while (i < s.length){
        if (j >= p.length || (p[j] !== '?' && p[j] !== '*' && s[i] !== p[j] )){
            if (star === -1){
                return false;
            }else{
                j = star + 1;
                i = istar++;
            }
        }else if (p[j] === '*'){
            star = j++;
            istar = i;
        }else{
            i++; j++;
        }
    }
    while (j < p.length){
        if (p[j++] !== '*') return false;
    }
    return true;
};