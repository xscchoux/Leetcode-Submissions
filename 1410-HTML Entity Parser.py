class Solution:
    def entityParser(self, text: str) -> str:
        hmap = {'&quot;':'"', '&apos;':'\'', '&gt;':'>', '&lt;':'<', '&frasl;':'/'}
        
        for k, v in hmap.items():
            text = text.replace(k, v)
            
        text = text.replace('&amp;', '&')
        
        return text