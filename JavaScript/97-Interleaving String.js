/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
var isInterleave = function(s1, s2, s3) {
    const n1 = s1.length, n2 = s2.length, n3 = s3.length;
    if (n1 + n2 !== n3) return false;
    let wrongPath = new Set();
    
    let dfs = (i, j, k) =>{
        if (wrongPath.has(`${i}-${j}`)) return false;
        
        if (k === n3) return true;
        
        let res = false;
        if (i < n1 && s1[i] === s3[k]) res = dfs(i+1, j, k+1);
        if (j < n2 && s2[j] === s3[k]) res = res || dfs(i, j+1, k+1);
        
        if (res){
            return true;
        }else{
            wrongPath.add(`${i}-${j}`);
            return false;
        }
    }
    return dfs(0,0,0);
};