/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var threeSumMulti = function(arr, target) {
    let hmap = new Map();
    let count = 0;
    
    for (let char of arr){
        hmap.set(char, (hmap.get(char)||0) + 1 );
    }
    
    for (let num1 of hmap.keys()){
        for (let num2 of hmap.keys()){
            let num3 = target - num1 - num2;
            if (!hmap.has(num3)){
                continue;
            }
            let count1 = hmap.get(num1), count2 = hmap.get(num2), count3 = hmap.get(num3);
            if (num1 === num2 && num2 === num3){
                count += count1*(count1-1)*(count1-2)/6;
            }else if(num1 === num2){
                count += count3*count1*(count1-1)/2;
            }else if (num1 < num2 && num2 < num3){
                count += count1*count2*count3;
            }
        }
    }
    return count%(Math.pow(10,9) + 7);  
};