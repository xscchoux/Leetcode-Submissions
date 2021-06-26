/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    let res = [[1]];
    let dp = [1];
    
    for (let i=2; i<=numRows; i++){
        let tmp = new Array(i).fill(1);
        for (let j=1; j<i-1; j++){
            tmp[j] = dp[j] + dp[j-1];
        }
        res.push(tmp);
        dp = tmp;
    }
    return res;
};