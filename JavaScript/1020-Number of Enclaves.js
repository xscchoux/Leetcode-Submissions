/**
 * @param {number[][]} grid
 * @return {number}
 */
var numEnclaves = function(grid) {
    const row = grid.length, col = grid[0].length;
    
    let dfs = (r, c) =>{
        grid[r][c] = 0;
        for (let [dr, dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
            const newR = r + dr, newC = c + dc;
            if (0<=newR && newR<row && 0<=newC && newC<col && grid[newR][newC] === 1){
                dfs(newR, newC);
            }
        }
    }
    
    let res = 0;
    
    for (let r of [0, row-1]){
        for (let c=0; c<col; c++){
            if (grid[r][c] === 1){
                dfs(r, c);
            }
        }
    }
    
    for (let r=0; r<row; r++){
        for (let c of [0, col-1]){
            if (grid[r][c] === 1){
                dfs(r, c);
            }
        }
    }
    
    for (let r=1; r<row-1; r++){
        for (let c=1; c<col-1; c++){
            if (grid[r][c] === 1) res++;
        }
    }
    return res;
};