class Solution:
    def compress(self, chars: List[str]) -> int:
        ind = 0
        totLength = 0
        
        while ind < len(chars):
            chars[totLength] = chars[ind]
            totLength += 1
            
            length = 0
            while ind+length < len(chars) and chars[ind+length] == chars[ind]:
                length += 1
            ind += length
            
            if length > 1:
                numCount = list(str(length))
                chars[totLength:totLength+len(numCount)] = numCount
                totLength += len(numCount)
                
        return totLength