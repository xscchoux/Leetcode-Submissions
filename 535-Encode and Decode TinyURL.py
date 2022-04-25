class Codec:
    hmap = collections.defaultdict(str)
    c = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        hashStr = []
        for i in range(6):
            hashStr.append(self.c[random.randint(0, 61)])
        encoded = "".join(hashStr)
        if encoded in self.hmap:
            hashStr = encode(longUrl)
        self.hmap[encoded] = longUrl
        return encoded

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.hmap[shortUrl]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))