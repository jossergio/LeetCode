class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        
        resposta = 0 # Por padrão
        
        for i in range (len (nums)):
            
            unicos = dict ()
            tmp = list ()
            
            for j, v in enumerate (nums [i:]):
                
                if not unicos.get (v): # Se ainda não existe, retorna None, que é falso
                    unicos [v] = True # Só para conter um valor para unicidade
                    tmp.append (v)
                else:
                    break # Sai do laço interno
            
            resposta = max (resposta, sum (tmp))
            
        return resposta

