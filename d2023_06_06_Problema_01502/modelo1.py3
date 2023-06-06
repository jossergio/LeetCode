class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr = sorted (arr) # Aproveita a variável
        dif = arr [1] - arr [0] # Sempre há dois, pela definição do problema
        ant = arr [1]
        for v in arr [2:]:
            if v - ant != dif:
                return False
            ant = v
        return True
    
