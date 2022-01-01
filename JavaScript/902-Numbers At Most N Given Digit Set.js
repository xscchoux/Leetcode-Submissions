/**
 * @param {string[]} digits
 * @param {number} n
 * @return {number}
 */
var atMostNGivenDigitSet = function(digits, n) {
    let res = 0, strN = n.toString();

    for (let i=1; i<strN.length; i++){
        res += Math.pow(digits.length, i);
    }
    
    for (let i=0; i<strN.length; i++){
        let matchPrefix = false;
        for (let d of digits){
            if (parseInt(d) < parseInt(strN[i])){
                res += Math.pow(digits.length, strN.length-i-1);
            }else if (parseInt(d) === parseInt(strN[i])){
                matchPrefix = true;
                break;
            }
        }
        if (!matchPrefix) return res;
    }
    return res + 1;
};