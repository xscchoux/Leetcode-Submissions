/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.n = nums.length;
    this.nums = nums;
    this.BITree = new Array(this.n+1).fill(0);
    
    for (let i=0; i<this.n; i++){
        this.updateBITree(i+1, nums[i]);
    }
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
NumArray.prototype.updateBITree = function(BITindex, val) {
    while (BITindex <= this.n){
        this.BITree[BITindex] += val;
        BITindex += BITindex&(-BITindex);
    }
};

NumArray.prototype.update = function(index, val) {
    const diff = val - this.nums[index];
    this.nums[index] = val;
    this.updateBITree(index+1, diff);
};

NumArray.prototype.getSum = function(BITindex) {
    let res = 0;
    while (BITindex > 0){
        res += this.BITree[BITindex];
        BITindex -= BITindex&(-BITindex);
    }
    return res;
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function(left, right) {
    return this.getSum(right+1) - this.getSum(left);
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * obj.update(index,val)
 * var param_2 = obj.sumRange(left,right)
 */