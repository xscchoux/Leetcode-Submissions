var exist = function(board, word) {
    let row = board.length, col = board[0].length;
    
    let dfs = (word, r, c) =>{
        if (!word.length){
            return true;
        }
        else if (r>=0 && r<row && c>=0 && c<col && word[0] == board[r][c]){

            let tmp = board[r][c];
            board[r][c] = '#';
            if (dfs(word.substr(1), r+1, c) || dfs(word.substr(1), r-1, c) || dfs(word.substr(1), r, c+1) || dfs(word.substr(1), r, c-1)){
                return true;
            }
            board[r][c] = tmp;
            return false;
        }
        else {
            return false;
        }
    }
    for (let r=0; r<row; r++){
        for (let c=0; c<col; c++){
            if (dfs(word, r, c)){
                return true;
            }
        }
    }
    return false;
};