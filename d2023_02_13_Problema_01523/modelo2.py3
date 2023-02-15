class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if low % 2 == 1:
            low -= 1 # Par anterior
        if high % 2 == 1:
            high += 1 # Par posterior
        return ((high - low) // 2)
    
