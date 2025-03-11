class Solution:
    def applySubstitutions(self, replacements: List[List[str]], text: str) -> str:
        hmap = defaultdict(str)
        for k, v in replacements:
            hmap[k] = v
        
        while text.count('%') > 1:
            for x in re.findall(r"%([^%]+)%", text):
                if x in hmap:
                    text = text.replace(f"%{x}%", hmap[x])

        return text