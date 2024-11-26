class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        perdedores = set ([e [1] for e in edges])
        return -1 if n - len (perdedores) > 1 else (set (range (n)) - perdedores).pop () # Só ficará um, mesmo, neste segundo caso

