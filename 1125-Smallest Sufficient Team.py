class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        
# first try, O(people * people * 2^skill)
        hmap = defaultdict(int)
        for i, c in enumerate(req_skills):
            hmap[c] = i
        
        N = len(req_skills)
        states = defaultdict(list)
        states[0] = []
        
        for index, p in enumerate(people):
            curr = 0
            for skill in p:
                idx = hmap[skill]
                curr |= (1<<idx)

            tmp = dict()
            for k, v in states.items():
                if k|curr != k:
                    if k|curr not in states:
                        if k|curr in tmp:
                            if len(tmp[k|curr]) > len(v) + 1:
                                tmp[k|curr] = v + [index]
                        else:
                            tmp[k|curr] = v + [index]
                    else:
                        if len(states[k|curr]) > len(v) + 1:
                            states[k|curr] = v + [index]
            states.update(tmp)
        
        
        return states[(1<<N)-1]
    
    
# Another solution. Note that dictionary size cannot be changed druing iteration
# O(people * people * 2^skill)

        hmap = defaultdict(int)
        for i, c in enumerate(req_skills):
            hmap[c] = i
        
        N = len(req_skills)
        states = defaultdict(int)
        states[0] = 0
        
        for index, p in enumerate(people):
            curr = 0
            for skill in p:
                idx = hmap[skill]
                curr |= (1<<idx)

            for k, v in list(states.items()):  # avoid RuntimeError: dictionary changed size during iteration
                bitCountV = v.bit_count()
                if k|curr != k:
                    if k|curr not in states or states[k|curr].bit_count() > bitCountV + 1:
                            states[k|curr] = v | (1<<index)
        ans = []
        answer_mask = states[(1<<N)-1]
        
        for i in range(len(people)):
            if (answer_mask >> i) & 1:
                ans.append(i)
                
        return ans