class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        perdedores = [0] * n
        for e in edges:
            perdedores [e[1]] += 1
        campeoes = [i for i, v in enumerate (perdedores) if v == 0]
        return -1 if len (campeoes) > 1 else campeoes [0] # Só ficou um, mesmo

