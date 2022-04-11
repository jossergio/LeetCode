class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        
        m = len (grid)
        n = len (grid [0])
        
        k %= (m * n) # Ajusta para k não ser maior que o tamanho total de grid
        
        if k == 0: # Iria girar e voltar pro mesmo lugar
            return grid
        
        tmp = list ()
        
        for linha in grid:
            tmp.extend (linha)
        
        tmp = tmp [-k:] + tmp [0:-k]
        
        resposta = list ()
        
        while len (tmp) > 0:
            resposta.append (tmp [:n])
            tmp = tmp [n:]
        
        return resposta
        
