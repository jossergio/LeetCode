class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        ref = arr [len (arr) - 1] + 1 # Valor para referência do fim do vetor
        tmp = sorted (list (set ([x for x in range (1, ref)]) - set (arr))) # Valores são 1-begin; ref já segue isso
        print (tmp)
        while len (tmp) < k:
            tmp.append (ref) # Adiciona o seguinte...
            ref += 1 # ... e segue para o próximo
        return tmp [k - 1]
    
