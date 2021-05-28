/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let row = new Array(9).fill(0).map(() => new Set());
    let col = new Array(9).fill(0).map(() => new Set());
    let box = new Array(9).fill(0).map(() => new Set());
    
    let float2int = (value) =>{
        return value | 0;
    }
    
    for (let r=0; r<9; r++){
        for (let c=0; c<9; c++){
            if (board[r][c] !== '.'){
                row[r].add(board[r][c]);
                col[c].add(board[r][c]);
                box[3*float2int(r/3) + float2int(c/3)].add(board[r][c]);
            }
        }
    }
    
    let backtrack = (r, c) =>{
        if (r === 9) {
            return true;
        }
        let nr = (c+1 === 9)? r+1: r;
        let nc = (c+1 === 9)? 0: c+1;
        if (board[r][c] !== "."){
            return backtrack(nr, nc);
        }else{
            for (let num=1; num <= 9; num++){
                let curr = num.toString();
                let boxIdx = 3*float2int(r/3) + float2int(c/3);
                if (!row[r].has(curr) && !col[c].has(curr) && !box[boxIdx].has(curr)){
                    row[r].add(curr);
                    col[c].add(curr);
                    box[3*float2int(r/3) + float2int(c/3)].add(curr);
                    board[r][c] = curr;
                    
                    if (backtrack(nr,nc)) return true;
                    
                    board[r][c] = ".";
                    box[3*float2int(r/3) + float2int(c/3)].delete(curr);                    
                    col[c].delete(curr);
                    row[r].delete(curr);
                }
            }
            return false;
        }
    }
    backtrack(0, 0);
};