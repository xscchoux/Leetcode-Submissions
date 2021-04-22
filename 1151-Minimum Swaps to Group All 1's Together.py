class Solution(object):
    def minSwaps(self, data):
        """
        :type data: List[int]
        :rtype: int
        """
        ones = sum(data)
        currOne = maxOne = sum(data[:ones])
        
        for right in range(ones, len(data)):
            currOne += data[right] - data[right-ones]
            maxOne = max(maxOne, currOne)
        
        return ones-maxOne