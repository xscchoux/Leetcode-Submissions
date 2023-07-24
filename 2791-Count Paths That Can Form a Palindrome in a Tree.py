class Solution:
    def countPalindromePaths(self, parent: List[int], s: str) -> int:
# https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/discuss/3805574/Python-dfs-%2B-bitmask-solution-with-explanation
#   The path from node a to node b 
# = the path from a to lca + the path from b to lca
# = letter's frequency(a) ^ letter's frequency(lca) ^ letter's frequency(b) ^ letter's frequency(lca) = letter's frequency(a) ^ letter's frequency(b)
        self.res = 0
        
        child = defaultdict(set)
        for i in range(1, len(parent)):
            child[parent[i]].add(i)
            
        count = defaultdict(int)
        count[0] = 1
        N = len(s)
        
        
        def dfs(idx, bitmask):
            for nxt in child[idx]:
                nxt_bitmask = bitmask^(1<<(ord(s[nxt])-ord('a')))
                self.res += count[nxt_bitmask]
                
                for i in range(26):
                    self.res += count[nxt_bitmask^(1<<i)]
                
                count[nxt_bitmask] += 1
                dfs(nxt, nxt_bitmask)
                
        dfs(0, 0)
        
        return self.res