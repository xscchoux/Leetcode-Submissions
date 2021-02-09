/**
 * @param {number[][]} grid
 * @return {number}
 */
var numDistinctIslands = function(grid) {
    let shape = new Set();
    const row = grid.length, col = grid[0].length;
    
    let dfs = (r, c, arr) =>{
        const [x,y] = arr
        let res = x.toString() + y.toString();
        for (let [dr, dc] of [[0,1],[1,0],[0,-1],[-1,0]]){
            newR = r + dr;
            newC = c + dc;
            if (0<=newR && newR<row && 0<=newC && newC<col && grid[newR][newC] === 1){
                grid[newR][newC] = 0;
                res += dfs(newR, newC, [x+dr, y+dc]);
            }
        }
        return res;
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if(grid[r][c] === 1){
                grid[r][c] = 0;
                shape.add(dfs(r, c, [0, 0]));
            }
        }
    }
    return shape.size;
};