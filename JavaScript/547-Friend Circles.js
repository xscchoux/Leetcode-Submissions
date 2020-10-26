/**
 * @param {number[][]} M
 * @return {number}
 */
var findCircleNum = function(M) {
    
    let number = M.length;
    
    let res = 0;
    let visited = new Set();
    
    let dfs = (curr)=>{
        for (let c=0; c<number; c++){
            if (M[curr][c] === 1 && !visited.has(c)){
                visited.add(c);
                dfs(c);
            }
        }
    }
    
    for (let c=0; c<number; c++){
        if (visited.has(c)) continue;
        else{
            dfs(c)
            res += 1;
        }
    }
    return res;
};