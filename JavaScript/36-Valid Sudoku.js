/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let row = new Array(), col = new Array(), box = new Array();
    for (let i=0; i<9; i++){
        row.push(new Set());
        col.push(new Set());
        box.push(new Set());
    }
    
    // Don't fill the array as follows:
    // let row = new Array(9).fill(new Set());
    // let col = new Array(9).fill(new Set());
    // let box = new Array(9).fill(new Set());
    
    for (let r=0; r<9; r++){
        for (let c=0; c<9; c++){
            let curr = board[r][c];
            if (curr === ".") continue;
            let boxNum = Math.floor(r/3)*3 + Math.floor(c/3)
            if (row[r].has(curr) || col[c].has(curr) || box[boxNum].has(curr)){
                return false;
            }
            row[r].add(curr);
            col[c].add(curr);
            box[boxNum].add(curr);
        }
    }
    return true;
};
