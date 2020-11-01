class Solution(object):
    def canFormArray(self, arr, pieces):
        """
        :type arr: List[int]
        :type pieces: List[List[int]]
        :rtype: bool
        """
        hmap = dict()
        for piece in pieces:
            hmap[piece[0]] = piece
        index = 0
        
        while index < len(arr):
            if arr[index] not in hmap or arr[index:index+len(hmap[arr[index]])] != hmap[arr[index]]:
                return False
            else:
                index += len(hmap[arr[index]])
        
        return True