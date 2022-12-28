class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        sobras = [c - p for c, p in zip (capacity, rocks)]
        sobras.sort ()
        i = 0
        cheios = 0
        while (i < len (sobras) and additionalRocks > 0):
            additionalRocks -= sobras [i] # Mesmo se zero
            if additionalRocks >= 0:
                cheios += 1
            i += 1
        return cheios
    
