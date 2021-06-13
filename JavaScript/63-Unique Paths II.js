/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    if (obstacleGrid[0][0]) return 0;
    
    const m = obstacleGrid.length, n = obstacleGrid[0].length;
    let dp = new Array(m+1).fill().map( x=> new Array(n+1).fill(0));
    dp[0][1] = 1
    for (let i = 1; i<=m; i++){
        for (let j=1; j<=n; j++){
            if (obstacleGrid[i-1][j-1] === 1){
                dp[i][j] = 0
            }else{
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m][n];
};