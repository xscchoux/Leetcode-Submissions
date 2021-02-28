/**
 * @param {string} S
 * @return {number}
 */
var minFlipsMonoIncr = function(S) {
    const n = S.length;
    let dp0 = 0, dp1 = 0;
    
    for (let i=0; i<n; i++){
        if (S[i] === '0'){
            dp1 = Math.min(dp0, dp1) + 1;
        }else{
            dp1 = Math.min(dp0, dp1);
            dp0 = dp0 + 1;
        }
    }
    
    return Math.min(dp1, dp0);
};