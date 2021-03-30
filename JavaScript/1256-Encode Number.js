/**
 * @param {number} num
 * @return {string}
 */
var encode = function(num) {
    if (num===0) return "";
    
    let length = 1, res = "";
    num--;
    
    while (num >= 1<<length ){
        num -= 1<<length;
        length++;
    }

    for (let i=0; i<length; i++, num>>=1){
        if (num&1){
            res = "1" + res;
        }else{
            res = "0" + res;
        }
    }
    return res;
};