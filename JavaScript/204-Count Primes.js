/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    if (n <= 2) return 0;
    
    let arr = new Array(n).fill(1);
    arr[0] = 0;
    arr[1] = 0;
    
    for (let i=2; i < Math.sqrt(n)+1; i++){
        if (arr[i] !== 0){
            for (let j = i+i; j < n; j+=i){
                arr[j] = 0;
            }
        }
    }
    return arr.reduce(function(acc, x){return acc+x;})
};