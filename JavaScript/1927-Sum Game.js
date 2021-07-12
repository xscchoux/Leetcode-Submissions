/**
 * @param {string} num
 * @return {boolean}
 */
var sumGame = function(num) {
    const N = num.length;
    let diff = 0; cnt = 0;
    
    for (let i=0; i<num.length; i++){
        if (i<(N/2)){
            if (num[i] === "?"){
                cnt += 1;
            }else{
                diff += parseInt(num[i]);
            }
        }else{
            if (num[i] === "?"){
                cnt -= 1;
            }else{
                diff -= parseInt(num[i]);
            }
        }
    }
    if (cnt%2) return true;
    if ( (diff > 0 && cnt >=0) || (diff<0 && cnt <= 0)) return true;
    
    return 4.5*Math.abs(cnt) !== Math.abs(diff);
};