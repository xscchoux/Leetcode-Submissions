/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isOneEditDistance = function(s, t) {
    let lengthS = s.length, lengthT = t.length;
    if ( Math.abs(lengthS-lengthT) > 1 || s === t ){
        return false;
    }
    
    let findDiff = false;
    let p1 = 0, p2 = 0;
    
    while (p1 < lengthS && p2 < lengthT){
        if (s[p1] !== t[p2]){
            if (findDiff) return false;
            findDiff = true;
            if (lengthS > lengthT) p2 -= 1;
            if (lengthT > lengthS) p1 -= 1;
        }
        p1+=1;
        p2+=1;
    }
    return true;
};