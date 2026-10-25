using LL = long long;
LL kMod = 1e9+7;

// segment tree using lazy tag from huifeng guan
class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;    
    LL info;  // the sum value over the range
    LL delta;
    bool tag; 
        
    SegTreeNode(int a, int b, int val)  // init for range [a,b] with val
    {                 
        tag = 0;
        delta = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val;
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }
    
    SegTreeNode(int a, int b, vector<int>& val)  // init for range [a,b] with the same-size array val
    {                 
        tag = 0;
        delta = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val[a];
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    }
    
    void pushDown()
    {
        if (tag==1 && left)
        {
            left->info += delta * (left->end - left->start + 1);            
            left->delta += delta;
            right->info += delta * (right->end - right->start + 1);
            right->delta += delta;
            left->tag = 1;
            right->tag = 1;
            tag = 0;
            delta = 0;
        }        
    } 
    
    void updateRangeBy(int a, int b, int val)     // increase range [a,b] by val
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info += val * (end-start+1);
            delta += val;
            tag = 1;
            return;
        }

        if (left)
        {            
            pushDown();
            left->updateRangeBy(a, b, val+delta);
            right->updateRangeBy(a, b, val+delta);
            delta = 0;
            tag = 0;
            info = left->info + right->info;  // write your own logic            
        }        
    }
    
    LL queryRange(int a, int b)     // query the sum within range [a,b]
    {
        if (b < start || a > end )
        {
            return 0;  // check with your own logic
        }
        if (a <= start && end <=b)
        {
            return info;  // check with your own logic
        }
        
        if (left)
        {
            pushDown();     
            LL ret = left->queryRange(a, b) + right->queryRange(a, b);        
            info = left->info + right->info;    // check with your own logic
            return ret;
        }
        
        return info;   // should not reach here
    }  
};


class Solution {
public:
    int sumCounts(vector<int>& nums) {
        LL res = 0;
        int N = nums.size();
        vector<int> prev(N, -1); // closet previous index with same value as nums[i]
        unordered_map<int, int> hmap;

        for (int i=0; i<N; i++) {
            if (hmap.contains(nums[i])) {
                prev[i] = hmap[nums[i]];
            }
            hmap[nums[i]] = i;
        }

        SegTreeNode* sgt = new SegTreeNode(0, N-1, 0);

        vector<int> dp(N, 0);
        // dp[i]: sum of squares of distinct counts using all subarrays within nums[j..i] where j = 0..i 
        // square[j:i]: sum of the square of distinct values in subarray num[j:i]
        // count[j:i]: sum of distinct values in subarray num[j:i]
        // (k is the previous index with the same value as nums[i])
        // dp[i] = sum(square[j:i]) for j = 0...i
        //       = sum(square[j:i-1]) for j = 0...k  +  sum(square[j:i]) for j = k+1...i
        //       = sum(square[j:i-1]) for j = 0...k  +  sum(count[j:i]^2) for j = k+1...i
        //       = sum(square[j:i-1]) for j = 0...k  +  sum((count[j:i-1]+1)^2) for j = k+1...i
        //       = sum(square[j:i-1]) for j = 0...k  
        //       + sum(count[j:i-1]^2) for j = k+1...i-1
        //       + sum(2*count[j:i-1]) for j = k+1...i-1
        //       + 1 for j=k+1...i 
        // dp[i] = sum(square[j:i-1]) for j = 0...i-1 + sum(2*count[j:i-1]) for j = k+1...i-1 + (i-k)       
        //       = dp[i-1] + + sum(2*count[j:i-1]) for j = k+1...i-1 + (i-k)  
        
        for (int i=0; i<N; i++) {
            dp[i] = i==0?0:dp[i-1];
            int k = prev[i];
            dp[i] = (dp[i] + 2*sgt->queryRange(k+1, i-1))%kMod;
            dp[i] = (dp[i] + (i-k))%kMod;
            
            sgt->updateRangeBy(k+1, i, 1);
        }

        for (int i=0; i<N; i++) {
            res = (res + dp[i])%kMod;
        }

        return res;
    }
};