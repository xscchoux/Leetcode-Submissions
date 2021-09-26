/**
 * @param {number[][]} board
 * @return {number}
 */
var movesToChessboard = function(board) {
    const n = board.length;
    
    for (let r=0; r<n; r++){
        for (let c=0; c<n; c++){
            if (board[0][0]^board[r][0]^board[0][c]^board[r][c] === 1){
                return -1;
            }
        }
    }
    
    let rowOnes = 0, colOnes = 0, rowSwap = 0, colSwap = 0;
    
    for (let i=0; i<n; i++){
        rowOnes += board[0][i];
        colOnes += board[i][0];
        rowSwap += board[0][i] === i%2;
        colSwap += board[i][0] === i%2;
    }
    
    if (rowOnes < n>>1 || rowOnes > (n+1)>>1 || colOnes < n>>1 || colOnes > (n+1)>>1 ){
        return -1;
    }
    
    if (n%2){
        if (rowSwap%2) rowSwap = n - rowSwap;
        if (colSwap%2) colSwap = n - colSwap;
    }else{
        rowSwap = Math.min(rowSwap, n-rowSwap);
        colSwap = Math.min(colSwap, n-colSwap);
    }
    
    return (rowSwap + colSwap) >>1 ;
};