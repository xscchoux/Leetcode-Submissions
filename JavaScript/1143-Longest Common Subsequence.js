/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2){
    let len1 = text1.length, len2 = text2.length;
    let dp = new Array(len2+1).fill().map(()=>new Array(len1+1).fill(0));

    for (let r=1; r<=len2; r++){
        for (let c=1; c<=len1; c++){
            dp[r][c] = text2[r-1] === text1[c-1]? dp[r-1][c-1] + 1 : Math.max(dp[r][c-1], dp[r-1][c]);
        }
    }
    
    return dp[len2][len1];
};