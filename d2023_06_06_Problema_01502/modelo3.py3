class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort ()
        dif = arr [1] - arr [0] # Sempre há dois, pela definição do problema
        for i in range (2, len (arr)):
            if arr [i] - arr [i - 1] != dif:
                return False
        return True
    
