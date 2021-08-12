class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
# categorized by sorted string, O(N*k*logk), N:length of strs, k: length of the longest word

        hmap = collections.defaultdict(list)
        for string in strs:
            sortedS = "".join(sorted(string))
            hmap[sortedS].append(string)
        
        return hmap.values()
    
# categorized by count, O(N*k)

        hmap = collections.defaultdict(list)
        for string in strs:
            count = [0]*26
            for s in string:
                count[ord(s)-ord('a')] += 1
            hmap[tuple(count)].append(string)
        
        return hmap.values()
        