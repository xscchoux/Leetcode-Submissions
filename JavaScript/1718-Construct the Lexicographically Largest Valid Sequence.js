/**
 * @param {number} n
 * @return {number[]}
 */
var constructDistancedSequence = function(n) {
    let used = new Set();
    let length = 2*n - 1;
    let res = new Array(length).fill(0);
    
    let backtrack = (i) =>{
        if (i === length){
            return true;
        }
        if (res[i] !== 0){
            return backtrack(i+1);
        }else{
            for (let num = n; num >= 1; num--){
                if (num === 1 && !used.has(num)){
                    res[i] = num;
                    used.add(num);
                    if (backtrack(i+1)) return true;
                    used.delete(num);
                    res[i] = 0
                } else if (num !== 1 && !used.has(num) && i + num < length && res[i+num] === 0){
                    res[i] = num;
                    res[i+num] = num;
                    used.add(num);
                    if (backtrack(i+1)) return true;
                    used.delete(num);
                    res[i] = 0;
                    res[i+num] = 0;
                }
            }
        }
        return false
    }
    backtrack(0);
    return res;
};