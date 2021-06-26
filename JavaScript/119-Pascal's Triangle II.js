/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let dp = [1];
    for (let i=1; i<=rowIndex; i++){
        let tmp = new Array(i+1).fill(1);
        for (let j=1; j<=i-1; j++){
            tmp[j] = dp[j] + dp[j-1];
        }
        dp = tmp;
    }
    return dp;
};