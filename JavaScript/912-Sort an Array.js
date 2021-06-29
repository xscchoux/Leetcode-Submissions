/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    let mergeSort = (arr) =>{
        if (arr.length < 2) return arr;
        const mid = Math.floor(arr.length/2);
        let leftArr = mergeSort(arr.slice(0, mid));
        let rightArr = mergeSort(arr.slice(mid));
        
        let i=0, j=0, k=0;
        while (i<leftArr.length && j<rightArr.length){
            if (leftArr[i] < rightArr[j]){
                arr[k] = leftArr[i];
                i++;
            }else{
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while (i<leftArr.length){
            arr[k] = leftArr[i];
            i++;k++;
        }
        while (j<rightArr.length){
            arr[k] = rightArr[j];
            j++;k++;
        }        
        return arr;
    }
    return mergeSort(nums);
};