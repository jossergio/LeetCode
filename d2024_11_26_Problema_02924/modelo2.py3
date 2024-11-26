class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        perdedores = set ()
        for e in edges:
            perdedores.add (e [1]) # Indiferente se já está ou não
        campeoes = set (range (n)) - perdedores
        return -1 if len (campeoes) > 1 else campeoes.pop () # Só ficou um, mesmo

