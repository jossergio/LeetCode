class Solution:
    def pegarProximo (self, visitados: List [bool], proximo: int)  -> int:
        for i in range (proximo, len (visitados)):
            if not visitados [i]:
                return i
        return -1 # Não há mais
    
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
        proximo = self.pegarProximo (visitados, 0)
        resposta = -1 # Por padrão
        while (proximo != -1):
            acompanhar = list ()
            ciclo = self.buscar (edges, acompanhar, proximo, visitados)
            if ciclo != -1:
                resposta = ciclo if resposta == -1 else max (resposta, ciclo)
            proximo = self.pegarProximo (visitados, proximo)
        return resposta
    
