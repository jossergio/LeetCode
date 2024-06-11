class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cont = Counter (arr1)
        resposta = list ()
        for i in arr2:
            resposta.extend ([i] * cont [i])
            cont.pop (i) # Para formar um resto
        resposta.extend (sorted (cont.elements ()))
        return resposta
    
