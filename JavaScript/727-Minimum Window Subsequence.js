/**
 * @param {string} s1
 * @param {string} s2
 * @return {string}
 */
var minWindow = function(s1, s2) {
    let p1 = 0, p2 = 0;
    let res = "", prevLen = s1.length+1;
    
    while (p1 < s1.length){
        if (s1[p1] === s2[p2]){
            p2++;
            if (p2 === s2.length){
                p2--;
                let i = p1;
                while (p2 >= 0){
                    if(s1[i] === s2[p2]){
                        p2--;
                    }
                    i--;
                }
                p2++;i++;
                if (p1-i+1 < prevLen){
                    prevLen = p1-i+1;
                    res = s1.substring(i, p1+1);
                }
                p1 = i+1;
            }else{
                p1++;
            }
        }else{
            p1++;
        }
    }
    return res;
};