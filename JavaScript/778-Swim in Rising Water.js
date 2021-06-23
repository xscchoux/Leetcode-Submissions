/**
 * @param {number[][]} grid
 * @return {number}
 */
var swimInWater = function(grid) {
    // binary search, O(N^2*logN^2)
    const N = grid.length;
    
    let bfs = (mid) =>{
        if (grid[0][0] > mid) return false;
        
        let queue =[[0,0]];
        let visited = new Set();
        visited.add(0);
        
        while (queue.length){
            [r, c] = queue.pop();
            if (r === N-1 && c === N-1){
                return true;
            }
            for (let [dr, dc] of [[0,1],[1,0],[-1,0],[0,-1]]){
                let newR = r + dr, newC = c + dc;
                if(newR>=0 && newR < N && newC>=0 && newC<N && !visited.has(newR*N + newC) && grid[newR][newC] <= mid){
                    queue.push([newR, newC]);
                    visited.add(newR*N+newC)
                }
                
            }
        }
        return false;
    }
    
    let left = 0, right = N*N-1;
    
    while (left +1 < right){
        let mid = left + Math.floor((right-left)/2);
        if (bfs(mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    if (bfs(left)){
        return left;
    }else{
        return right;
    }
};