/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestDistance = function(grid) {
    let offices = new Array();
    const row = grid.length, col = grid[0].length;
    const N = row*col;
    let res = new Array(row).fill().map(()=>new Array(col).fill(0));
    let reachable = new Array(row).fill().map(()=>new Array(col).fill(0));
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (grid[r][c] === 1){
                res[r][c] = Number.POSITIVE_INFINITY;
                offices.push([r,c]);
            }else if (grid[r][c] === 2){
                res[r][c] = Number.POSITIVE_INFINITY;
            }
        }
    }

    for (let office of offices){
        let queue = [];
        queue.push([office[0], office[1], 0]);
        let visited = new Set();
        visited.add(office[0]*N + office[1]);
        let officesVisited = 0;
        
        while (queue.length > 0){
            let size = queue.length;
            for (let i=0; i<size; i++){
                let [currR, currC, step] = queue.shift();
                for (let [dr, dc] of [[1,0], [0,1], [-1,0], [0,-1]]){
                    let newR = currR+dr, newC = currC+dc;
                    if (0<=newR && newR<row && 0<=newC && newC<col && !visited.has(newR*N+newC)){
                        visited.add(newR*N+newC);
                        if (grid[newR][newC] === 1){
                            officesVisited += 1;
                        }else if (grid[newR][newC] === 0){
                            queue.push([newR, newC, step+1]);
                            res[newR][newC] += step+1;
                            reachable[newR][newC] += 1;
                        }
                    }
                }
            }
        }
        if (offices.length !== officesVisited + 1){
            return -1;
        }
    }
    
    let ans = Number.POSITIVE_INFINITY;
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (grid[r][c] === 0 && reachable[r][c] === offices.length){
                ans = Math.min(ans, res[r][c]);
            }
        }
    }
    
    return (ans === Number.POSITIVE_INFINITY)? -1:ans;
};