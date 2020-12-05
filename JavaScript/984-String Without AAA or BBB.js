/**
 * @param {number} A
 * @param {number} B
 * @return {string}
 */
var strWithout3a3b = function(A, B) {
    let diff = A-B;
    let res = [];
    
    if (diff > 0){
        let group = Math.min(diff, B);
        res = res.concat(Array.from({length:group}).fill("aab"));
        A -= 2*group;
        B -= group;
    } else if (diff < 0){
        let group = Math.min(-diff, A);
        res = res.concat(Array.from({length:group}).fill("bba"));
        B -= 2*group;
        A -= group;
    }

    let remain = Math.min(A, B);
    res = res.concat(Array.from({length:remain}).fill("ab"));
    A -= remain;
    B -= remain;
    res = res.concat(Array.from({length:A}).fill("a"), Array.from({length:B}).fill("b")) ;
    
    return res.join("");
};