class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        resposta = list ()
        tmp = list ()
        
        def adicionar (base: int):
            
            nonlocal tmp
            nonlocal resposta
            
            if len (tmp) == k:
                if sum (tmp) == n:
                    resposta.append (tmp)
            else:
                for b in range (base + 1, 10):
                    if sum (tmp) + b <= n:
                        tmp.append (b)
                        adicionar (b)
                        tmp = tmp [:-1]
                    else:
                        break
                        
        adicionar (0) # Base começa de zero, para inicar o laço com +1
        
        return resposta
    
