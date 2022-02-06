class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res = []
        i = 0
        while i < len(words):
            j = i
            tot = 0
            while j < len(words) and tot <= maxWidth:
                if j == i:
                    tot += len(words[j])
                else:
                    tot += len(words[j]) + 1
                j+=1
            j-=1
            
            if tot > maxWidth:
                j-= 1
            
            if j == len(words)-1 or i == j: # last line or one word in a line
                tmp = " ".join(words[i:j+1])
                tmp += " "*(maxWidth-len(tmp))
                res.append(tmp)
            else:
                length = sum([len(words[ind]) for ind in range(i, j+1)])
                gapLen, biggerGapNum = divmod(maxWidth-length,j-i)
                tmp = words[i]
                ind = i+1
                while biggerGapNum > 0:
                    tmp += " "*(gapLen+1) + words[ind]
                    ind += 1
                    biggerGapNum-=1
                
                while ind <= j:
                    tmp += " "*(gapLen) + words[ind]
                    ind += 1
                res.append(tmp)
            i = j+1
        return res