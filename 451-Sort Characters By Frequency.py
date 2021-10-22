class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
# Hashmap + sort
        count = collections.Counter(s)
        
        res = ""
        
        for x in sorted(count.keys(), key = lambda x: -count[x]):
            res += x*count[x]
        return res
    
# bucket sort
        count = collections.Counter(s)
        maxVal = max(count.values())
        buckets = [[] for _ in range(maxVal+1)]
        for key in count.keys():
            buckets[count[key]].append(key)
        res = "" 
        for i in range(maxVal, -1, -1):
            for c in buckets[i]:
                res += c*i
                
        return res