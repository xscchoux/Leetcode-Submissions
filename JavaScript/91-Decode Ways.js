/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    if (s[0] === "0") return 0;
    
    const n = s.length;
    let dp = new Array(n+1).fill(0);
    dp[0] = 1; dp[1] = 1;

    for (let i=1; i<s.length; i++){
        if (+s[i]>=1 && +s[i] <= 9) dp[i+1] += dp[i];
        let twoNum = parseInt(s.substring(i-1,i+1));
        if (twoNum >= 10 && twoNum <= 26) dp[i+1] += dp[i-1];
        if (dp[i+1] === 0) return 0;
    }
    return dp[dp.length-1];
};