/**
 * @param {string} target
 * @return {string}
 */
var alphabetBoardPath = function(target) {
    
    let res = [];
    let prevR = 0, prevC = 0;
    
    for (let char of target){
        const code = char.charCodeAt(0) - 'a'.charCodeAt(0);
        const currR = Math.floor(code/5), currC = code%5;
        let diffR = currR - prevR, diffC = currC - prevC;
        while (diffC < 0) { res.push("L"); diffC++;}
        while (diffR < 0) { res.push("U"); diffR++;}
        while (diffC > 0) { res.push("R"); diffC--;}
        while (diffR > 0) { res.push("D"); diffR--;}
        res.push("!");
        [prevR, prevC] = [currR, currC];
    }
    return res.join('');
};