/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    let index_g = 0, index_s = 0;
    
    g.sort(function(a,b){return a-b;})
    s.sort(function(a,b){return a-b;})
    
    while (index_g < g.length && index_s < s.length){
        if (s[index_s] < g[index_g]){
            index_s++;
        }else{
            index_s++;
            index_g++;
        }
    }
    return index_g
    
};