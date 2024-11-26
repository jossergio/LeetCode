class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        campeoes = set (range (n))
        for e in edges:
            if e [1] in campeoes: # Testa a existência, primeiro, pois remove produz uma exceção caso não haja
                campeoes.remove (e [1]) # Tira os que são mais fracos
        return -1 if len (campeoes) > 1 else campeoes.pop () # Só ficou um, mesmo

