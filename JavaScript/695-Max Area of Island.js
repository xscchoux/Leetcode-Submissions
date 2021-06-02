/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let row = grid.length, col = grid[0].length;
    let res = 0;
    
    let dfs = (r, c) =>{
        if (0<=r && r<row && 0<=c && c<col && grid[r][c] === 1){
            grid[r][c] = 0;
            return 1 + dfs(r+1,c) + dfs(r-1,c) + dfs(r,c+1) + dfs(r, c-1);
        }else{
            return 0;
        }
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (grid[r][c] === 1){
                res = Math.max(res, dfs(r, c));
            }
        }
    }
    return res;
};