class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.
        
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        else:
            return "//".join( [s.replace('/','#/#') for s in strs]) + '//'  # need to consider the edge case: [""]
        

    def decode(self, s):
        """Decodes a single string to a list of strings.
        
        :type s: str
        :rtype: List[str]
        """
        
        if not s:
            return []
        else:
            return [seg.replace('#/#','/') for seg in s.split('//')][:-1]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))