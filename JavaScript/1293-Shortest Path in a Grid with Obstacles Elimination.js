/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var shortestPath = function(grid, k) {   
    const row = grid.length, col = grid[0].length;
    visited = new Set()
    queue = [[0, 0, k, 0]];
    
    while (queue.length > 0){
        let [currR, currC, remain, step] = queue.shift();
        if (currR === row-1 && currC === col-1){
            return step;
        }
        for (let [dr, dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
            let newR = currR+dr, newC = currC+dc;
            if (0<=newR && newR<row && 0<=newC && newC<col){
                if (grid[newR][newC] === 1 && remain > 0 && !visited.has(`${newR}-${newC}-${remain-1}`)){
                    visited.add(`${newR}-${newC}-${remain-1}`);
                    queue.push([newR, newC, remain-1, step+1]);
                }else if(grid[newR][newC] === 0 && !visited.has(`${newR}-${newC}-${remain}`)){
                    visited.add(`${newR}-${newC}-${remain}`);
                    queue.push([newR, newC, remain, step+1]);
                }
            }
        }
    }
    return -1;
};