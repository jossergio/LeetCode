class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        resposta = list ()
        tmp = list ()
        
        def adicionar (base: int, soma: int):
            
            if len (tmp) == k:
                if soma == n:
                    resposta.append (list (tmp))
            else:
                for b in range (base + 1, 10):
                    if soma < n:
                        tmp.append (b)
                        adicionar (b, soma + b)
                        tmp.pop ()
                    else:
                        break
                        
        adicionar (0, 0) # Base começa de zero, para iniciar o laço com +1
        
        return resposta
    
