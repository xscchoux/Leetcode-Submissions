var ProductOfNumbers = function() {
    this.preProduct = [1];
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
    if (num === 0){
        this.preProduct = [1];
    }else{
        this.preProduct.push(this.preProduct[this.preProduct.length-1]*num);
    }
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
    if (k >= this.preProduct.length){
        return 0;
    }else{
        return this.preProduct[this.preProduct.length-1]/this.preProduct[this.preProduct.length-1-k];
    }
};

/** 
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */