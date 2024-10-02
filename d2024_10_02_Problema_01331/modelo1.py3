class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = dict ()
        for i, v in enumerate (sorted (set (arr))):
            rank [v] = i + 1 # O rank é 1-begin
        for i in range (len (arr)): # Usarei o próprio vetor original
            arr [i] = rank [arr [i]]
        return arr
    
