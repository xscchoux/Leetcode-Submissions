/**
 * @param {string} p
 * @return {number}
 */
var findSubstringInWraproundString = function(p) {
    let endAt = new Array(26).fill(0);
    let length = 0
    
    for (let i=0; i<p.length; i++){
        if (i!==0 && (p[i].charCodeAt(0) === p[i-1].charCodeAt(0)+1 || p[i].charCodeAt(0) === p[i-1].charCodeAt(0) - 25)){
            length += 1;
        }else{
            length = 1;
        }
        
        endAt[p[i].charCodeAt(0) - 'a'.charCodeAt(0)] = Math.max( length, endAt[p[i].charCodeAt(0) - 'a'.charCodeAt(0)] )
    }
    
    return endAt.reduce(function(acc,x){
        return acc+x;
    } ,0);
};