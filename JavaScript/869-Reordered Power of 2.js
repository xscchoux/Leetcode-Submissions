/**
 * @param {number} N
 * @return {boolean}
 */
var reorderedPowerOf2 = function(N) {
    let sortedN = N.toString().split("").sort().join("");
    
    for (let i=0; i<30; i++){
        if ((1<<i).toString().split("").sort().join("") === sortedN){
            return true;
        } 
    }
    return false;
};