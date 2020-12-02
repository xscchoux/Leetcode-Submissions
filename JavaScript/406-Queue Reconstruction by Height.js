/**
 * @param {number[][]} people
 * @return {number[][]}
 */
var reconstructQueue = function(people) {
    let res = [];
    people.sort(function(a,b){
        if (a[0] !== b[0]){
            return b[0] - a[0];
        } else{
            return a[1] - b[1];
        }
    })
    for (let p of people){
        res.splice(p[1], 0, p);
    }
    return res;
};