/**
 * @param {number[]} A
 * @return {number}
 */
var numberOfArithmeticSlices = function(A) {
    if (A.length < 3) return 0;
    let dp = new Array(A.length).fill(0);
    let res = 0;
    
    for (let i = 2; i<A.length; i++){
        if (A[i-1] - A[i-2] === A[i] - A[i-1]){
            dp[i] = dp[i-1] + 1;
            res += dp[i];
        }
    }
    return res;
};