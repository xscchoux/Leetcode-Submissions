class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        N = len(reward1)
        arr = sorted(range(N), key = lambda x:reward2[x]-reward1[x])
        
        res = 0
        for i in range(k):
            res += reward1[arr[i]]
        
        for i in range(k, N):
            res += reward2[arr[i]]
            
        return res