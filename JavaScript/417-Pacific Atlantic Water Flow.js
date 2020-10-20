/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var pacificAtlantic = function(matrix) {
    if (!matrix || !matrix[0]) return [];
    
    let pacific = new Set(), atlantic = new Set();
    
    const row = matrix.length, col = matrix[0].length;
    
    let dfs = (prev, r, c, ocean) =>{
        if (r<0 || r>=row || c<0 || c>=col || ocean.has( r.toString() + "," + c.toString() )) return;
        if (matrix[r][c] < prev) return;
        ocean.add(r.toString()+","+c.toString());
        dfs(matrix[r][c], r-1, c, ocean);
        dfs(matrix[r][c], r+1, c, ocean);
        dfs(matrix[r][c], r, c+1, ocean);
        dfs(matrix[r][c], r, c-1, ocean);
    }
    
    for (let r=0; r<row; r++){
        dfs(-1, r, 0, pacific);
        dfs(-1, r, col-1, atlantic);
    }
    
    for (let c=0; c<col; c++){
        dfs(-1, 0, c, pacific);
        dfs(-1, row-1, c, atlantic);
    }
    return Array.from(new Set([...pacific].filter(x => atlantic.has(x)))).map(x=>x.split(",").map(x=>Number(x)));
};