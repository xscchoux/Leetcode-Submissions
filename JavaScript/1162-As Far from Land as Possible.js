/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    const row = grid.length, col = grid[0].length;
    let land = new Array();
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (grid[r][c] === 1) land.push([r,c]);
        }
    }
    
    if (land.length === 0 || land.length === row*col) return -1;
    
    let count = 0;
    
    while (land.length){
        let newLand = new Array();
        while (land.length){
            let [currR, currC] = land.pop();
            for (let [dr, dc] of [[0,1], [1,0], [-1,0], [0,-1]]){
                let newR = currR + dr;
                let newC = currC + dc;
                if (0 <= newR && newR < row && 0 <= newC && newC < col && grid[newR][newC] === 0){
                    newLand.push([newR,newC]);
                    grid[newR][newC] = 1;
                }
            }
        }
        count += 1;
        land = newLand;
    }
    return count-1;
};