class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        resposta = list ()
        tmp = list ()
        
        def adicionar (i: int, base: int):
            
            nonlocal tmp
            nonlocal resposta
            
            if i == 0:
                if sum (tmp) == n:
                    try:
                        if resposta.index (tmp) > -1: # Só para ter um valor
                            pass
                    except:
                        resposta.append (tmp)
            else:
                for b in range (base + 1, 10):
                    if sum (tmp) + b <= n:
                        tmp.append (b)
                        adicionar (i - 1, b)
                        tmp = tmp [:-1]
                    else:
                        break
                        
        adicionar (k, 0) # Base começa de zero, para inicar o laço com +1
        
        return resposta
    
