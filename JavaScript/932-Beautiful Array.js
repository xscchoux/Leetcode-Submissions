/**
 * @param {number} N
 * @return {number[]}
 */
var beautifulArray = function(N) {
    let res = new Array(1).fill(1);
    
    while (res.length < N){
        let tmp = new Array();
        
        for (let num of res){
            if (num*2-1 <= N){
                tmp.push(num*2-1);
            }
        }
        for (let num of res){
            if (num*2 <= N){
                tmp.push(num*2);
            }
        }
        res = tmp;
    }
    return res;
};