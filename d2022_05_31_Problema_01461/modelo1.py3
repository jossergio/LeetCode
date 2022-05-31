class Solution:
    valores = list ()
    
    def formarBinarios (self, k: int):
        pot = 2 ** k
        bits = ["0", "1"]
        
        for i in range (0, pot):
            v = i
            tmp = ""
            
            while v != 0:
                tmp += bits [int (v % 2)]
                v //= 2
            
            tmp = tmp [::-1] # Inverte
            tmp = tmp.zfill (k) # Preenche com zeros à esquerda
            
            self.valores.append (tmp)
        
    def hasAllCodes(self, s: str, k: int) -> bool:
        self.valores.clear () # LeetCode reaproveita o objeto nos testes
        self.formarBinarios (k)    

        for v in self.valores:
            try:
                s.index (v)
            except:
                return False
            
        return True # Encontrou todos
    
