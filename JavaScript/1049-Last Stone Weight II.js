/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeightII = function(stones) {

//knapsack
    
    const summ = stones.reduce((acc, x) => acc+x);
    const upperbound = Math.floor(summ/2);
    let dp = new Array(upperbound+1).fill(false);
    dp[0] = true;
        
    for (let stone of stones){
        for (let i=dp.length-1; i>0; i--){
            if (i-stone < 0) break;
            if (dp[i-stone]) dp[i] = true;
        }
        if (dp[dp.length-1]) return summ%2;
    }
    
    for (let i=dp.length-1; i>=0; i--){
        if (dp[i]) return summ-2*i;
    }
};