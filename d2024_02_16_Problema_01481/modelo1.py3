class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        contagem = sorted ([a for a in Counter (arr).values ()])
        while k > 0:
            if len (contagem) == 0:
                break
            if contagem [0] <= k:
                k -= contagem [0]
                contagem.pop (0);
            else:
                k = 0 # Só para forçar sair, sem break
        return len (contagem)
    
