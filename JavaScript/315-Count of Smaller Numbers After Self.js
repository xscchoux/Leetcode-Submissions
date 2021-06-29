/**
 * @param {number[]} nums
 * @return {number[]}
 */
// Merge Sort
var countSmaller = function(nums) {
    const N = nums.length;
    let res = new Array(N).fill(0);
    
    let mergeSort = (arr) =>{
        if (arr.length <= 1) return arr;
        const mid = arr.length >> 1;
        let leftArr = mergeSort(arr.slice(0, mid));
        let rightArr = mergeSort(arr.slice(mid));
        for (let i = arr.length-1; i>=0; i--){
            if (!rightArr.length || (leftArr.length && nums[leftArr[leftArr.length-1]] > nums[rightArr[rightArr.length-1]])){
                res[leftArr[leftArr.length-1]] += rightArr.length;
                arr[i] = leftArr.pop();
            }else{
                arr[i] = rightArr.pop();
            }
        }
        return arr;
    }
    
    indexArr = new Array(N).fill().map((val,ind)=>ind);
    mergeSort(indexArr);
    return res;
};

// Binary Indexed Tree
var BIT = function(N) {
    this.BITarr = new Array(N+1).fill(0);
    this.len = N+1;
}

BIT.prototype.update = function(ind, val) {
    while (ind < this.len){
        this.BITarr[ind] += val;
        ind += ind&(-ind);
    }
};

BIT.prototype.query = function(ind) {
    let res = 0;
    while (ind > 0){
        res += this.BITarr[ind];
        ind -= ind&(-ind);
    }
    return res;
};


var countSmaller = function(nums) {
    let numArr = [...new Set(nums)];
    const N = numArr.length;
    numArr.sort(function(a,b){return a-b});
    let hmap = new Map();
    for (let i=0; i<N; i++){
        hmap.set(numArr[i], i+1);
    }
    let BITree = new BIT(N);

    for (let i=nums.length-1; i>=0; i--){
        let index = hmap.get(nums[i]);
        nums[i] = BITree.query(index-1);
        BITree.update(index, 1);
    }
    return nums;
};