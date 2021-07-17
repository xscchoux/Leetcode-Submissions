/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let arr1 = version1.split("."), arr2 = version2.split(".");
    
    while (arr1.length && arr2.length){
        let int1 = Number(arr1.shift()), int2 = Number(arr2.shift());
        if (int1 > int2){
            return 1;
        }else if(int2 > int1){
            return -1
        }
    }
    while (arr1.length){
        let int1 = Number(arr1.shift());
        if (int1 > 0) return 1;
    }
    
    while (arr2.length){
        let int2 = Number(arr2.shift());
        if (int2 > 0) return -1;
    }
    
    return 0;
};