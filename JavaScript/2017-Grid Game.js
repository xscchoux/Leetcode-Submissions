/**
 * @param {number[][]} grid
 * @return {number}
 */
var gridGame = function(grid) {
    let res = Number.POSITIVE_INFINITY;
    let top = grid[0].reduce((acc, x)=>acc+x), bottom = 0;
    
    for (let i=0; i<grid[0].length; i++){
        top -= grid[0][i];
        res = Math.min(res, Math.max(top, bottom));
        bottom += grid[1][i];
    }
    
    return res;
};