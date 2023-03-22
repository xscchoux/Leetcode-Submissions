# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def get_hostname(url):
            return url.split('/')[2]
        
        hostname = get_hostname(startUrl)
        visited = set([startUrl])
        
        def dfs(url, parser):
            for nxt in parser.getUrls(url):
                if get_hostname(nxt) == hostname and nxt not in visited:
                    visited.add(nxt)
                    dfs(nxt, parser)
                    
        dfs(startUrl, htmlParser)
        
        return list(visited)