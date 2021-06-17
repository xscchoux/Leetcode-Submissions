/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    len_t = t.length, count = 0, start = 0;
    let hmap_t = new Map();
    let res = [0, Number.POSITIVE_INFINITY];
    for (let char of t){
        hmap_t.set(char, (hmap_t.get(char)||0) + 1 );
    }
    
    for (let i=0; i<s.length; i++){
        hmap_t.set(s[i], (hmap_t.get(s[i])||0) - 1);
        
        if (hmap_t.get(s[i]) >= 0){
            count += 1;
        }
        
        while (count === len_t){
            hmap_t.set(s[start], hmap_t.get(s[start]) + 1);
            if (hmap_t.get(s[start]) > 0){
                count -= 1;
            }
            if (res[1] - res[0] > i- start ){
                res = [start, i];
            }
            start+=1;
        }
    }
    
    return (res[1] === Number.POSITIVE_INFINITY)? '': s.substring(res[0], res[1]+1);
};