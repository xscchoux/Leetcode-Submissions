// https://leetcode.cn/problems/fancy-sequence/solutions/3917656/lan-geng-xin-deng-jie-zhuan-hua-pythonja-csvl/

// mul = 1, add = 0
// a' = a*mul + add
// 1. addAll  -> add + (added value)
// 2. multAll -> a'' = a*mul*(multiplied value) + add*(multiplied value), so 
//                     mul = mul*(multiplied value), add = add*(multiplied value)
// when we append a new value, (new value)' = ((new value) - add) / mul
// when we call getIndex(idx), return arr[idx]*mul + add

constexpr int kMod = 1e9+7;
using LL = long long;
class Fancy {
public:
    vector<LL> arr;
    LL add = 0, mul = 1;
    Fancy() {
        
    }
    LL powWithMod(LL a, LL b) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    void append(int val) {
        LL newVal = ( ((val - add + kMod)%kMod) * powWithMod(mul, kMod-2))%kMod;
        arr.push_back(newVal);
    }
    
    void addAll(int inc) {
        add = (add + inc)%kMod;
    }
    
    void multAll(int m) {
        mul = mul*m%kMod;
        add = add*m%kMod;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;

        return (arr[idx]*mul + add)%kMod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */