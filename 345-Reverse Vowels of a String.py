class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        arr = list(s)
        left, right = 0, len(s) - 1
        vowels = set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"])
        
        while left < right:
            while left < right and s[left] not in vowels:
                left += 1
            while left < right and s[right] not in vowels:
                right -= 1
                
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1
            
        return "".join(arr)