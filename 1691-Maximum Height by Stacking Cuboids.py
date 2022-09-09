class Solution(object):
    def maxHeight(self, cuboids):
        """
        :type cuboids: List[List[int]]
        :rtype: int
        """
# https://www.youtube.com/watch?v=nyJe6_4_MTs
# a primitive way, O(6N*6N)
#         N = len(cuboids)
#         dp = [0]*(6*N)
#         points = []
        
#         for i in range(len(cuboids)):
#             w, l, h = cuboids[i]
#             points.append((w, l, h, i))
#             points.append((w, h, l, i))
#             points.append((l, w, h, i))
#             points.append((l, h, w, i))
#             points.append((h, w, l, i))
#             points.append((h, l, w, i))
            
#         points.sort(key = lambda x:(x[0], x[1], x[2]))
        
#         for i in range(len(points)):
#             dp[i] = points[i][2]
#             for j in range(i):
#                 if points[j][0] <= points[i][0] and points[j][1] <= points[i][1] and points[j][2] <= points[i][2] and points[j][3] != points[i][3]:
#                     dp[i] = max(dp[i], dp[j] + points[i][2])
                    
#         return max(dp)
    
    
# a clever way, O(N^2)
        N = len(cuboids)
        for cuboid in cuboids:
            cuboid.sort()
        cuboids.sort()
        dp = [0]*N
            
        # cuboids.sort(key = lambda x:(x[0], x[1], x[2]))
        cuboids.sort()
        
        for i in range(len(cuboids)):
            dp[i] = cuboids[i][2]
            for j in range(i):
                if cuboids[j][0] <= cuboids[i][0] and cuboids[j][1] <= cuboids[i][1] and cuboids[j][2] <= cuboids[i][2]:
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2])
                    
        return max(dp)