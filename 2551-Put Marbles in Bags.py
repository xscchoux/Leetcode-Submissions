class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        if k == len(weights):
            return 0
        
        arr = []
        for a, b in zip(weights, weights[1:]):
            arr.append((a + b))
        
        arr.sort()
            
        return sum(arr[len(arr)-k+1:]) - sum(arr[:k-1])
