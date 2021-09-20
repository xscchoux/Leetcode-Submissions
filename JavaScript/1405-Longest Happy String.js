/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
    let toPut = [[a, "a"], [b, "b"], [c, "c"]];
    let res = "";
    
    toPut.sort(function(a, b){
        return a[0]-b[0];
    })
    
    let find = (index, count) =>{
        let ans = ""
        let toGet = Math.min(count, toPut[index][0]);
        for (let i=0; i<toGet; i++) ans += toPut[index][1];
        toPut[index][0] -= toGet
        toPut.sort(function(a,b){return a[0]-b[0];})
        return ans;
    }
    
    res += find(2, 2);
    
    while (toPut[2][0] > 0){
        let mostOccured = toPut[2][1];
        if (mostOccured !== res[res.length-1]){
            res += find(2, 2);
        }else if (toPut[1][0] > 0){
            res += find(1, 1);
        }else{
            break;
        }
    }
    
    return res;
};