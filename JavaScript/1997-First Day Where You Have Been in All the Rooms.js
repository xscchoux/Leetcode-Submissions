/**
 * @param {number[]} nextVisit
 * @return {number}
 */
var firstDayBeenInAllRooms = function(nextVisit) {
    const kMod = 1000000007, N = nextVisit.length;
    let dp = new Array(N).fill(0);
    for (let i=1; i<N; i++){
        let nxt = nextVisit[i-1];
        dp[i] = dp[i-1] + 2 + (dp[i-1] - dp[nxt]);
        dp[i] = (dp[i] + kMod)%kMod;
    }
    return dp[N-1];
};