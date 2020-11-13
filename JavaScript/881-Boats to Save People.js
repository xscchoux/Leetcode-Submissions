/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function(people, limit) {
    people.sort(function(a,b){return a-b;});
    
    let start = 0, end = people.length-1;
    let res = 0;
    
    while (start <= end){
        res += 1;
        if (people[start] + people[end] <= limit){
            start++;end--;
        }
        else{
            end--;
        }
    }
    return res;
};