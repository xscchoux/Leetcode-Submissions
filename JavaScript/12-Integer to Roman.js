/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    const symMap = [ [1000,"M"], [900,"CM"], [500,"D"], [400,"CD"], [100,"C"], [90,"XC"], 
                    [50,"L"], [40,"XL"], [10,"X"], [9,"IX"], [5,"V"], [4,"IV"], [1,"I"]];
    
    let res = '';
    
    for (let [val, symbol] of symMap){
        if (num >= val){
            let remainder = num%val;
            let count = parseInt(num/val);
            res += symbol.repeat(count);
            num = remainder;
        }
    }
    return res;
};