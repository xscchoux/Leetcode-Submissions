class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        
# First try
        res = []
        count = defaultdict(int)
        used = defaultdict(set)
        
        for name in names:
            if name in count:
                currCount = count[name]
                while currCount in used[name]:
                    count[name] += 1
                    currCount += 1
                used[name].add(currCount)
                name = name+"("+ str(currCount) +")"
                
                
            elif name[-1] == ")":
                ind = len(name) - 2
                while ind >= 0 and name[ind] != "(":
                    ind -= 1
                num = int(name[ind+1:len(name)-1])
                used[name[:ind]].add(num)
                
            count[name] = 1
            res.append(name)

        return res


# a little better
        used = set()
        count = defaultdict(int)
        res = []
        
        for name in names:

            currCount = count[name]
            new = name
            while new in used:
                currCount += 1
                new = f'{name}({currCount})'
            used.add(new)
            count[name] = currCount
            res.append(new)
            
        return res