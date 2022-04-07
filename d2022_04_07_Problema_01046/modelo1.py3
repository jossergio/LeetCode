class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        stones.sort (reverse = True)
        
        while len (stones) > 1:
            
            item1 = stones.pop (0)
            item2 = stones.pop (0)
            result = item1 - item2
            if result > 0:
                if len (stones) > 0 and result >= stones [0]:
                    stones.insert (0, result)
                else:
                    stones.append (result)
                    stones.sort (reverse = True)
        
        return stones [0] if len (stones) > 0 else 0

