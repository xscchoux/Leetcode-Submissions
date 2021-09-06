/**
 * @param {number[][]} land
 * @return {number[][]}
 */
var findFarmland = function(land) {
    let row = land.length, col = land[0].length;
    let res = new Array();
    
    let dfs = (r, c) =>{
        land[r][c] = 0;
        let maxr = r,  maxc = c;
        for (let [dr, dc] of [[1,0],[0,1],[-1,0],[0,-1]]){
            let nr = r+dr, nc = c+dc;
            if (0<=nr && nr<row && 0<=nc && nc<col && land[nr][nc] === 1){
                let [rr, cc] = dfs(nr, nc);
                maxr = Math.max(r, rr);
                maxc = Math.max(c, cc);
            }
        }
        return [maxr, maxc];
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (land[r][c] === 1){
                let [nr, nc] = dfs(r, c);
                res.push([r, c, nr, nc]);                
            }
        }
    }
    return res;
};