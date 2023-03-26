class Solution:
    def buscar (self, edges: List [int], acompanhar: List [int], atual: int, visitados: List [bool]) -> int:
        if visitados [atual]:
            if atual in acompanhar:
                return len (acompanhar) - acompanhar.index (atual)
            else:
                return -1
        # else
        visitados [atual] = True
        if edges [atual] == -1:
            return -1 # Nâo tem mais para onde ir
        # else
        acompanhar.append (atual)
        return self.buscar (edges, acompanhar, edges [atual], visitados)
    
    def longestCycle(self, edges: List[int]) -> int:
        visitados = [False] * len (edges)
        resposta = -1 # Por padrão
        for proximo in range (len (edges)):
            if visitados [proximo]:
                continue
            # else
            acompanhar = list ()
            ciclo = self.buscar (edges, acompanhar, proximo, visitados)
            if ciclo != -1:
                resposta = ciclo if resposta == -1 else max (resposta, ciclo)
        return resposta
    
