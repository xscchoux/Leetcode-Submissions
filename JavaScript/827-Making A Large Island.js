/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestIsland = function(grid) {
    const N = grid.length;
    let area = new Map();
    
    let dfs = (r, c, index) =>{
        grid[r][c] = index;
        let area = 1
        for (let [dr, dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
            let newR = r+dr, newC = c+dc;
            if (0<=newR && newR<N && 0<=newC && newC < N && grid[newR][newC] === 1){
                area += dfs(newR, newC, index);
            }
        }
        return area;
    }
    
    let index = 2;
    for (let r=0; r<N; r++){
        for (let c=0; c<N; c++){
            if (grid[r][c] === 1){
                grid[r][c] = index;
                area.set(index, 1);
                for (let [dr, dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
                    let newR = r+dr, newC = c+dc;
                    if (0<=newR && newR<N && 0<=newC && newC<N && grid[newR][newC] === 1){
                        area.set(index, area.get(index) + dfs(newR, newC, index));
                    }
                }
                index += 1;
            }
        }
    }
    
    let res = Math.max(...area.values(),0);
    
    for (let r=0; r<N; r++){
        for (let c=0; c<N; c++){
            if (grid[r][c] === 0){
                let islands = new Set();
                let currArea = 1;
                for (let [dr, dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
                    let newR = r+dr, newC = c+dc;
                    if (0<=newR && newR<N && 0<=newC && newC<N && grid[newR][newC] > 1){
                        islands.add(grid[newR][newC]);
                    }
                }
                for (let index of islands){
                    currArea += area.get(index);
                }
                res = Math.max(res, currArea);
            }
        }
    }
    
    return res;
};