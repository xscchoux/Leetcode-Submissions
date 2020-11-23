/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function(s) {
    let countA = 0;
    for (let char of s){
        if (char === 'a'){
            countA += 1;
        }
    }
    let res = countA, curr = countA;
    
    for (let char of s){
        if (char === 'a'){
            curr -= 1;
        }else{
            curr += 1;
        }
        res = Math.min(res, curr);
    }
    return res;
};