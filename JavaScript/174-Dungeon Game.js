/**
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
    
    // dp[r][c]: minimum health point at (r,c) to go to the bottom-right corner
    // Time complexity:O(n^2), Space complexity:O(n^2)
    const row = dungeon.length, col = dungeon[0].length;
    let dp = new Array(row+1).fill().map(()=> new Array(col+1).fill(Number.POSITIVE_INFINITY));
    dp[row][col-1] = 1;
    
    for (let r=row-1; r>=0; r--){
        for (let c=col-1; c>=0; c--){
            dp[r][c] = Math.max(1, Math.min(dp[r+1][c], dp[r][c+1]) - dungeon[r][c]);
        }
    }
    return dp[0][0];
    
//  Time complexity:O(n^2), Space complexity:O(n)
    const row = dungeon.length, col = dungeon[0].length;
    let dp = new Array(col+1).fill(Number.POSITIVE_INFINITY);
    dp[col-1] = 1;
    
    for (let r=row-1; r>=0; r--){
        for (let c=col-1; c>=0; c--){
            dp[c] = Math.max(1, Math.min(dp[c], dp[c+1]) - dungeon[r][c]);
        }
    }
    return dp[0];
    
};