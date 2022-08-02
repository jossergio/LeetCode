class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        lista = [x for linha in matrix for x in linha]
        
        return sorted (lista) [k - 1]

