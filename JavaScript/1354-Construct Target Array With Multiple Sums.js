/**
 * @param {number[]} target
 * @return {boolean}
 */
var isPossible = function(target) {
    let tot = target.reduce(function(x, acc){
        return x + acc;
    });
    let end = target.length;
    
    while (tot != end){
        let maxIndex = target.indexOf(Math.max(...target));
        let rest = tot - target[maxIndex];
        
        if (rest == 0 || rest >= target[maxIndex]){
            return false;
        }
        
        let tmp = target[maxIndex];
        
        if (target[maxIndex]%rest == 0){
            target[maxIndex] = rest;
        } else{
            target[maxIndex] = target[maxIndex] % rest;
        }
        tot = tot - tmp + target[maxIndex];
    }
    return true;
};