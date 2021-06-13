/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let indexA = a.length-1, indexB = b.length-1;
    let carry = 0;
    let res = "";
    
    while (indexA >= 0 || indexB >= 0){
        if (indexA >= 0){
            if (a[indexA] === '1'){
                carry += 1;
            }
            indexA--;
        }
        
        if (indexB >= 0){
            if (b[indexB] === '1'){
                carry += 1;
            }
            indexB--;
        }       
        
        res = (carry%2).toString() + res;
        carry = ~~(carry/2);
    }
    
    if (carry) res = "1" + res;
    
    return res;
    
};