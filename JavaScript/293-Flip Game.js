/**
 * @param {string} s
 * @return {string[]}
 */
var generatePossibleNextMoves = function(s) {
    let res = [];
    
    for (let i=0; i<s.length; i++){
        if (s.substring(i,i+2) === '++'){
            res.push(s.substring(0,i).concat("--").concat(s.substring(i+2)));
        }
    }
    return res;
};