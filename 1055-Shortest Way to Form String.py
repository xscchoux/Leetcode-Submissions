class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        
# dictionary + binary search
        hmap = collections.defaultdict(list)
        for i, c in enumerate(source):
            hmap[c].append(i)
        
        count = 1 # number of times we need to iterate through source
        ind = 0 # index of source
        
        for char in target:
            if char not in hmap:
                return -1
            currIdx = bisect_left(hmap[char], ind)
            if currIdx == len(hmap[char]):
                count += 1
                currIdx = 0
            ind = hmap[char][currIdx] + 1
            
        return count
    
# DP, store the index of c in source ahead of (or including) sourceIterator, O(26*N)
        Nsource= len(source)
        next_occurence = [defaultdict(int) for _ in range(Nsource)]
        next_occurence[Nsource-1][source[Nsource-1]] = Nsource-1
        
        for i in range(Nsource-2, -1, -1):
            next_occurence[i] = next_occurence[i+1].copy()
            next_occurence[i][source[i]] = i
        
        count = 1
        ind = 0 # sourceIterator
        for char in target:
            if char not in next_occurence[0]:
                return -1
            if ind == Nsource or char not in next_occurence[ind]:
                ind = 0
                count += 1
            ind = next_occurence[ind][char] + 1
            
        return count