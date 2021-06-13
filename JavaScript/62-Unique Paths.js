/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    
    let factorial = (num) =>{
        let res = 1;
        for (let i = 2; i <=num; i++){
            res *= i;
        }
        return res;
    }
    
    return factorial(m+n-2)/(factorial(m-1)*factorial(n-1));
};