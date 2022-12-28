class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        sobras = [c - p for c, p in zip (capacity, rocks)]
        cheios = 0
        for s in sorted (sobras):
            additionalRocks -= s # Mesmo se zero
            if additionalRocks >= 0:
                cheios += 1
            else:
                break # Não há mais pedras para encher os demais
        return cheios
    
