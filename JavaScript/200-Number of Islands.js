/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const row = grid.length, col = grid[0].length;
    let res = 0;
    
    let dfs = (r, c) =>{
        grid[r][c] = "0";
        for (let [dr,dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
            let newR = r+dr, newC = c+dc;
            if (0<=newR && newR<row && 0<=newC && newC<col && grid[newR][newC] === '1'){
                dfs(newR, newC);
            }
        }
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (grid[r][c] === '1'){
                dfs(r, c);
                res += 1;
            }
        }
    }
    return res;
};