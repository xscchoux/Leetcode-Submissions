/**
 * @param {character[][]} board
 * @return {number}
 */
var countBattleships = function(board) {
    let row = board.length, col = board[0].length;
    let res = 0;
    
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (board[r][c] === 'X'){
                if ((r === row-1 || (r < row-1 && board[r+1][c] == '.')) && 
                    (c === col-1 || (c<col-1 && board[r][c+1] == '.'))){
                    res += 1;    
                }
            }
        }
    }
    return res;
};