class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        arr = preorder.split(",")
        index = 0
        N = len(arr)
        
        def dfs():
            nonlocal index
            if index == N:
                return False
            if arr[index] == "#":
                return True
            
            index += 1
            left = dfs()
            if not left:
                return False
            
            index += 1
            right = dfs()
            if not right:
                return False
            
            return True
        
        if not dfs():
            return False
        
        return index == N-1