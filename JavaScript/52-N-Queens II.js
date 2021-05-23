/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let row = new Array(n).fill(false), col = new Array(n).fill(false);
    let diag1 = new Array(2*n-1).fill(false), diag2 = new Array(2*n-1).fill(false);
    let res = 0;
    
    let dfs = (r) =>{
        if (r === n){
            res += 1;
            return;
        }
        for (let c=0; c<n; c++){
            if (!row[r] && !col[c] && !diag1[r+c] && !diag2[r-c+n-1]){
                row[r] = true;
                col[c] = true;
                diag1[r+c] = true;
                diag2[r-c+n-1] = true;
                dfs(r+1);
                row[r] = false;
                col[c] = false;
                diag1[r+c] = false;
                diag2[r-c+n-1] = false;
            }
        }   
    }
    dfs(0);
    return res;
};