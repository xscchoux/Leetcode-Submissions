class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        N = len(accounts)
        parent = {i:i for i in range(N)}
        hmap = collections.defaultdict(int)  # email to index in accounts
        emailSet = set()
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(a, b):
            pa, pb = find(a), find(b)
            if pa!=pb:
                parent[pa] = pb
        
        for i, account in enumerate(accounts):
            for email in account[1:]:
                if email in hmap:
                    union(i, find(hmap[email]) )
                else:
                    hmap[email] = i
                emailSet.add(email)
                
        nameToEmail = collections.defaultdict(set)
        
        for email in emailSet:
            nameToEmail[find(hmap[email])].add(email)
        
        res = []
        for key, val in nameToEmail.items():
            res.append([accounts[key][0]] + sorted(list(val)))
        
        return res