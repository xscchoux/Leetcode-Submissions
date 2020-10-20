/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
// Time:O(N*k), Space:O(N)
var maxProfit = function(k, prices) {
    if (prices.length <= 1) return 0;
    
    if (2*k >= prices.length){
        let sum = 0;
        for (let i=1; i<prices.length; i++){
            if (prices[i]-prices[i-1] > 0) sum += prices[i] - prices[i-1];
        }
        return sum
    }
    
    let dp = new Array(2);
    
    for (let i=0; i<dp.length; i++){
        dp[i] = new Array(prices.length).fill(0);
    }
    
    for (let i=1; i<=k; i++){
        let lastMax = -prices[0];
        for (let j=1; j<prices.length; j++){
            dp[i%2][j] = Math.max(dp[i%2][j-1], prices[j]+lastMax);
            lastMax = Math.max(lastMax, dp[(i-1)%2][j]-prices[j]);
        }
    }
    return dp[k%2][prices.length-1];
};