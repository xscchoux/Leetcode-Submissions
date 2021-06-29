/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    let res = new Array();
    
    let dfs = (remain, space, curr) =>{
        const remainLen = remain.length;
        if (space === 0){
            if (!remainLen){
                res.push(curr.join("."));
            }
            return;
        }else{
            if (!remainLen){
                return;
            }
        }
        if(remain[0] === "0" && remainLen-1 <= 3*(space-1)){
            dfs(remain.substr(1), space-1, curr.concat(["0"]));   
        }
        for (let i=1; i<=3; i++){
            const currNum = Number(remain.substring(0,i));
            if (remain[0] !== "0" && remainLen-i >= 0 && remainLen-i <= 3*(space-1) && 1<=currNum && currNum<=255){
                dfs(remain.substr(i), space-1, curr.concat([remain.substring(0,i)]));
            }
        }
    }
    
    dfs(s, 4, new Array())
    return res  
};