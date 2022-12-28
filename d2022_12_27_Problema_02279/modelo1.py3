class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        sobras = list (map (lambda a: a [0] - a [1], zip (capacity, rocks)))
        sobras.sort ()
        i = 0
        while (i < len (sobras) and additionalRocks > 0):
            if sobras [i] != 0:
                additionalRocks -= sobras [i]
                if additionalRocks >= 0:
                    sobras [i] = 0 # Encheu e ainda sobrou
            i += 1
        return len ([a for a in sobras if a == 0])
    
