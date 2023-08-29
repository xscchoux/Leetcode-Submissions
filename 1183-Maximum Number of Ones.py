class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        # https://www.cnblogs.com/lz87/p/12521679.html
        count = [0]*(sideLength*sideLength)
        
        for r in range(height):
            for c in range(width):
                rMod = r%sideLength
                cMod = c%sideLength
                count[rMod*sideLength+cMod] += 1
        
        count.sort(reverse = True)
        
        return sum(count[:maxOnes])