/**
 * @param {number[][]} grid
 * @return {number}
 */
var countServers = function(grid) {
    if (!grid || !grid[0]) return 0;
    
    let row = grid.length, col = grid[0].length;
    let rowNum = new Array(row).fill(0), colNum = new Array(col).fill(0);
    let servers = new Set();
    
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (grid[r][c] === 1){
                rowNum[r] += 1;
                colNum[c] += 1;
                servers.add([r,c])
            }
        }
    }
    
    let res = 0;
    
    for (let [r,c] of servers){
        if (rowNum[r] > 1 || colNum[c] > 1){
            res += 1;
        }
    }
    return res;
};