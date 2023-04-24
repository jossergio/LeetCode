class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort ()
        while len (stones) > 1:
            result = stones.pop () - stones.pop ()
            if result > 0:
                stones.append (result)
                stones.sort ()
        return stones [0] if len (stones) > 0 else 0

