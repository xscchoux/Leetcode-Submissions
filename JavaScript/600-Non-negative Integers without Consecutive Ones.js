/**
 * @param {number} n
 * @return {number}
 */
var findIntegers = function(n) {
    let dp = new Array(32).fill(0);
    dp[0] = 1;
    dp[1] = 2;
    for (let i=2; i<32; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    let res = 0, pre = 0, k = 31;
    while (k >= 0){
        if (n & (1 << k)){
            res += dp[k];
            if (pre === 1) return res;
            pre = 1;
        }else{
            pre = 0;
        }
        k-= 1
    }
    return res+1;
};