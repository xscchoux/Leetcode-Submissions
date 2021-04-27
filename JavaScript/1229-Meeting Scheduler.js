/**
 * @param {number[][]} slots1
 * @param {number[][]} slots2
 * @param {number} duration
 * @return {number[]}
 */
var minAvailableDuration = function(slots1, slots2, duration) {
    let ind1 = 0, ind2 = 0;
    let sorting = (a,b) =>{
        return a[0] - b[0];
    }
    slots1.sort(sorting);
    slots2.sort(sorting);
    
    while (ind1 < slots1.length && ind2 < slots2.length){
        let start = Math.max(slots1[ind1][0], slots2[ind2][0]);
        let end = Math.min(slots1[ind1][1], slots2[ind2][1]);
        if (end-start >= duration){
            return [start, start+duration];
        }
        if (slots1[ind1][1] > slots2[ind2][1]){
            ind2++;
        }else{
            ind1++;
        }
    }
    return [];
};