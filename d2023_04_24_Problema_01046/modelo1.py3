class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-i for i in stones] # Atenção ao negativo
        heapify (heap)
        while len (heap) > 1:
            result = (-heappop (heap)) + heappop (heap)
            if result > 0:
                heappush (heap, -result)
        return -heap [0] if len (heap) > 0 else 0
    
