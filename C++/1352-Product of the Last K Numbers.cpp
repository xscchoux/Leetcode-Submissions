// first AC, O(1) add, O(1) getProduct
class ProductOfNumbers {
public:
    int lastZero = -1, idx = 0;
    vector<int> preProduct = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        idx++;
        if (num == 0) {
            preProduct.push_back(0);
            lastZero = idx;
        } else {
            if (preProduct.back() == 0) {
                preProduct.push_back(num);
            } else {
                preProduct.push_back(num*preProduct.back());
            }
        }
    }
    
    int getProduct(int k) {
        if (lastZero >= idx-k+1) return 0;
        int preIdx = idx-k;
        if (preIdx < 0 || preProduct[preIdx] == 0) return preProduct.back();
        return preProduct.back()/preProduct[preIdx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */



// Simpler but tricky, clear the vector when encountering 0
class ProductOfNumbers {
public:
    vector<int> preProduct = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            preProduct.clear();
            preProduct.push_back(1);
        } else {
            preProduct.push_back(num*preProduct.back());
        }
    }
    
    int getProduct(int k) {
        if (preProduct.size() - 1 < k) {
            return 0;
        } else {
            return preProduct.back()/preProduct[preProduct.size()-k-1];
        }
    }
};
