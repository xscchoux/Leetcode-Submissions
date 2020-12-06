/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var kthFactor = function(n, k) {
    let sqrtN = parseInt(Math.sqrt(n));
    let divisors = [];
    for (let i=1; i<=sqrtN; i++){
        if (n%i === 0){
            divisors.push(i);
            k -= 1;
            if (k===0){
                return i;
            }
        }
    }

    if ( sqrtN*sqrtN === n){
        k += 1;
    }
    
    if (k <= divisors.length){
        return n/divisors[divisors.length-k];
    }else{
        return -1;
    }
};