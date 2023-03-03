class Solution:
    def strStr(self, haystack: str, needle: str) -> int:        
        # double rolling hash, use a rolling hash pair to represent a substring
        kMod1 = 100000033
        radix1 = 26
        maxWeight1 = 1
        kMod2 = pow(2, 31) - 1
        radix2 = 27
        maxWeight2 = 1
        
        for _ in range(len(needle)):
            maxWeight1 = (maxWeight1*radix1)%kMod1
            maxWeight2 = (maxWeight2*radix2)%kMod2
            
        def hash_pair(string):
            hash1 = hash2 = 0
            factor1 = factor2 = 1
            for i in range(len(needle)-1, -1, -1):
                hash1 = (hash1 + (ord(string[i]) - ord('a'))*factor1)%kMod1
                factor1 = (factor1*radix1)%kMod1
                hash2 = (hash2 + (ord(string[i]) - ord('a'))*factor2)%kMod2
                factor2 = (factor2*radix2)%kMod2
            
            return [hash1%kMod1, hash2%kMod2]
        
        hash_needle = hash_pair(needle)
        
        for start in range(len(haystack)-len(needle)+1):
            if start == 0:
                hash_haystack = hash_pair(haystack)
            else:
                hash_haystack[0] = ((hash_haystack[0]*radix1)%kMod1 - (ord(haystack[start-1])-ord('a'))*maxWeight1%kMod1 + (ord(haystack[start+len(needle)-1])-ord('a'))%kMod1)%kMod1
                hash_haystack[1] = ((hash_haystack[1]*radix2)%kMod2 - (ord(haystack[start-1])-ord('a'))*maxWeight2%kMod2 + (ord(haystack[start+len(needle)-1])-ord('a'))%kMod2)%kMod2     
            
            if hash_needle == hash_haystack:
                return start
        
        return -1

    
# KMP algorithm

        def kmp_search(pattern, text):
            m = len(pattern)
            n = len(text)

            # Calculate prefix array
            prefix = [0] * m
            j = 0
            for i in range(1, m):
                while j > 0 and pattern[j] != pattern[i]:
                    j = prefix[j-1]
                if pattern[j] == pattern[i]:
                    j += 1
                prefix[i] = j

            # Perform KMP search
            j = 0
            for i in range(n):
                while j > 0 and pattern[j] != text[i]:
                    j = prefix[j-1]
                if pattern[j] == text[i]:
                    j += 1
                if j == m:
                    return i - m + 1

            return -1
        
        return kmp_search(needle, haystack)