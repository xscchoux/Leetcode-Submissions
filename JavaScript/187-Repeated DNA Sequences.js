/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
    const N = s.length, L = 10;
    if (N<=10) return [];
    
    let hmap = new Map([["A",0], ["C",1], ["G",2], ["T",3]]);
    let bitmask = 0, visited = new Set(), res = new Set();
    
    for (let start = 0; start <= N-L; start++){
        if (start === 0){
            for (let i=0; i<L; i++){
                bitmask <<= 2;
                bitmask |= hmap.get(s[i]);
            }
            visited.add(bitmask);
        }else{
            bitmask <<= 2;
            bitmask |= hmap.get(s[start+L-1]);
            bitmask &= ~(3<<(2*L));
            if (visited.has(bitmask)){
                res.add(s.substring(start, start+L));
            }else{
                visited.add(bitmask);
            }
        }
    }
    return [...res];
};