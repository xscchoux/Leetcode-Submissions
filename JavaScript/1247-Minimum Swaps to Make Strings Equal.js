/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumSwap = function(s1, s2) {
    let xCount = 0, yCount = 0;
    
    for (let i=0; i<s1.length; i++){
        if (s1[i] !== s2[i]){
            if (s1[i] === 'x'){
                xCount += 1;
            }else{
                yCount += 1;
            }
        }
    }
    if ((xCount + yCount) & 1 === 1){
        return -1;
    }
    return Math.floor(xCount/2) + Math.floor(yCount/2) + 2*(xCount&1); 
};