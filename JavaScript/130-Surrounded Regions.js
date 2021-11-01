/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    let row = board.length, col = board[0].length;
    
    let dfs = (r, c)=>{
        board[r][c] = "D";
        for (let [dr, dc] of [[1,0], [0,1], [0,-1], [-1,0]]){
            let newR = r+dr, newC = c+dc;
            if (0<=newR && newR<row && 0<=newC && newC<col && board[newR][newC] === "O"){
                dfs(newR, newC);
            }
        }
    }
    
    for (let r of [0, row-1]){
        for (let c=0; c<col; c++){
            if (board[r][c] === "O"){
                dfs(r, c);
            }
        }
    }
    
    for (let r=0; r<row; r++){
        for (let c of [0, col-1]){
            if (board[r][c] === "O"){
                dfs(r, c);
            }
        }
    }
    
    for (let r=1; r<row-1; r++){
        for (let c=1; c<col-1; c++){
            if (board[r][c] === "O") board[r][c] = "X";
        }
    }
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (board[r][c] === "D"){
                board[r][c] = "O";
            }
        }
    }
};
