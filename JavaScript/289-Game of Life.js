/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    if (board.length === 0 || board[0].length === 0) return
    
    let row = board.length, col = board[0].length;
    
    let count_neighbor = (r,c) => {
        let count = 0;
        for (rOffset = -1; rOffset < 2; rOffset++){
            for (cOffset = -1; cOffset < 2; cOffset++){
                if (rOffset === 0 && cOffset === 0) continue;
                if (r+rOffset >=0 && r+rOffset < row && c+cOffset >=0 && c+cOffset < col){
                    count += board[r+rOffset][c+cOffset] % 2;
                }
            }
        }
        return count;
    }
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            nbor = count_neighbor(r,c);
            if (nbor === 3 || (board[r][c] && nbor === 2)){
                board[r][c] += 2;
            }
        }
    }
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            board[r][c] >>= 1;
        }
    }
};