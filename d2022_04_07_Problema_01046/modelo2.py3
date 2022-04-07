class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        heap = [-i for i in stones] # Atenção ao negativo
        
        heapify (heap)
   
        while len (heap) > 1:
            
            item1 = -heappop (heap)
            item2 = -heappop (heap)
            result = item1 - item2
            if result > 0:
                heappush (heap, -result)
        
        return -heap [0] if len (heap) > 0 else 0

