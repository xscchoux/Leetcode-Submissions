/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    
    let factorialFunc = (num) =>{
        let res = 1;
        for (let x = 2; x<=num; x++){
            res *= x;
        }
        return res;
    }
    
    let arr = Array(n).fill().map((_, i) => (i+1).toString() );
    let factorial = factorialFunc(n);
    let res = new Array();
    --k;
    
    while (k > 0){
        factorial = factorial/n;
        let index = ~~(k/factorial);
        k = k%factorial;
        for (let i=0; i<arr.length; i++){
            if (arr[i] === null) continue;
            if (index === 0){
                res.push(arr[i]);
                arr[i] = null;
                break;
            }else{
                --index;
            }
        }
        n--;
    }
    
    for (let xx of arr){
        if (xx){
            res.push(xx);
        }
    }
    return res.join("");
};