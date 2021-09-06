/**
 * @param {number[][]} properties
 * @return {number}
 */
var numberOfWeakCharacters = function(properties) {
    properties.sort(function(a,b){
        return a[0] === b[0] ? (a[1]-b[1]) : (b[0] - a[0]);
    })
    
    let maxDefense = 0, res = 0;
    
    for (let [attack, defense] of properties){
        if (defense < maxDefense) res++;
        if (defense > maxDefense) maxDefense = defense;
    }
    return res;
};