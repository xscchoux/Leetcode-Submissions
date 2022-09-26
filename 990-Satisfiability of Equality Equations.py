class Solution(object):
    def equationsPossible(self, equations):
        """
        :type equations: List[str]
        :rtype: bool
        """
        parent = {c:c for c in "abcdefghijklmnopqrstuvwxyz"}
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
            
        def merge(a, b):
            pa, pb = find(a), find(b)
            parent[pa] = pb
        
        diff = []
        for equation in equations:
            if equation[1] == "=":
                merge(equation[0], equation[3])
            else:
                diff.append((equation[0], equation[3]))
        
        for a, b in diff:
            if find(a) == find(b):
                return False
            
        return True