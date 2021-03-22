/**
 * @param {number} n
 * @return {number}
 */
var countNumbersWithUniqueDigits = function(n) {
    
    let permutation = (n) =>{
        let res = 1;
        let multiply = 9;
        while (n > 0){
            res *= multiply;
            n--;multiply--;
        }
        return res;
    }
    
    let count = (n) =>{
        if (n === 0){
            return 1;
        }
        return 9*permutation(n-1) + count(n-1);
    }
    return count(n);
};