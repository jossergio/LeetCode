class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cont = Counter (arr1)
        resposta = list ()
        for i in arr2:
            resposta.extend ([i] * cont [i])
            cont.pop (i) # Para formar um resto
        for i in sorted (cont.keys ()):
            resposta.extend ([i] * cont [i])
        return resposta
    
