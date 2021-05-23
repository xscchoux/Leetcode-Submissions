/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    let row = new Array(n).fill(false), col = new Array(n).fill(false);
    let diag1 = new Array(2*n-1).fill(false), diag2 = new Array(2*n-1).fill(false);
    let res = [];
    let tmp = new Array(n).fill("");
    
    let dfs = (r) =>{
        if (r === n){
            res.push([...tmp]);
            return;
        }
        for (let c=0; c<n; c++){
            if (!row[r] && !col[c] && !diag1[r+c] && !diag2[r-c+n-1]){
                row[r] = true;
                col[c] = true;
                diag1[r+c] = true;
                diag2[r-c+n-1] = true;
                tmp[r] = ".".repeat(c) + "Q" + ".".repeat(n-1-c);
                dfs(r+1);
                tmp[r] = "";
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