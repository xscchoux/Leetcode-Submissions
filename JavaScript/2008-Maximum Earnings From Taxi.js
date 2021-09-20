/**
 * @param {number} n
 * @param {number[][]} rides
 * @return {number}
 */
var maxTaxiEarnings = function(n, rides) {
    let dp = new Array(n+1).fill(0);
    rides.sort(function(a,b){return a[1]-b[1];})
    const Nride = rides.length;
    let idx = 0;
    
    for (let i=1; i<=n; i++){
        if (rides[idx][1] === i){
            dp[i] = dp[i-1];
            while (idx < Nride && rides[idx][1] === i){
                dp[i] = Math.max(dp[i], dp[rides[idx][0]] + rides[idx][1]- rides[idx][0] + rides[idx][2] );
                idx++;
            }
            if (idx === Nride) return dp[i];            
        }else{
            dp[i] = dp[i-1];
        }    
    }
};