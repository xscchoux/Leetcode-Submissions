/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var nthUglyNumber = function(n, a, b, c) {
    let gcd = (n1, n2) =>{
        if (n1 === 0){
            return n2;
        }
        return gcd(n2%n1, n1);
    }
    
    let lcm = (n1, n2) =>{
        return n1*n2/gcd(n1, n2);
    }
    
    const lcmAB = lcm(a, b), lcmBC = lcm(b, c), lcmAC = lcm(a, c);
    const lcmABC = lcm(a, lcmBC);
    
    let left = 1, right = 2*10**9;
    
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        let k = Math.floor(mid/a) + Math.floor(mid/b) + Math.floor(mid/c) - Math.floor(mid/lcmAB) -Math.floor(mid/lcmBC) - Math.floor(mid/lcmAC) + Math.floor(mid/lcmABC);
        if (k>=n){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    if(Math.floor(left/a) + Math.floor(left/b) + Math.floor(left/c) - Math.floor(left/lcmAB) -Math.floor(left/lcmBC) - Math.floor(left/lcmAC) + Math.floor(left/lcmABC) === n){
        return left;
    }else{
        return right;
    }
    
};