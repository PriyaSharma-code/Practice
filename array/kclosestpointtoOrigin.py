#973. K Closest Points to Origin

import heapq
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for (i,y) in points:
            d = -(i*i + y*y)
            if(len(heap)==k):
                heapq.heappushpop(heap,(d,i,y))
            else:
                heapq.heappush(heap,(d,i,y))
        return [(x,y) for(d,x,y) in heap]