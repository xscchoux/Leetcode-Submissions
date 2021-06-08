/**
 * @param {number[]} answers
 * @return {number}
 */
var numRabbits = function(answers) {
    let hmap = new Map();
    for (let num of answers){
        hmap.set(num, (hmap.get(num)|| 0) + 1);
    }
    
    let res = 0;
    
    for (let [k, v] of hmap.entries()){
        if (v%(k+1) === 0){
            res += v;
        }else{
            res += (k+1)*Math.ceil(v/(k+1));
        }
    }
    return res;
};