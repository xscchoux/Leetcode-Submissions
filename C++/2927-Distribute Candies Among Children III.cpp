class Solution {
public:
    long long H(int n){
        // H(3, n)
        return (long long)(n+2)*(n+1)/2;
    }
    long long distributeCandies(int n, int limit) {
        if (n > 3*limit) return 0;
        
        long long allCase = H(n);
        if (n >= limit+1) allCase -= 3*H(n-limit-1);
        if (n >= 2*(limit+1)) allCase += 3*H(n-2*(limit+1));
        
        return allCase;
    }
};