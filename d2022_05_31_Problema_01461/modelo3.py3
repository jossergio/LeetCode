class BinariosK:
    def __init__ (self, k: int = 0):
        self.pot = 2 ** k
        self.k = k
        self.bits = ["0", "1"]
        
    def __iter__ (self):
        self.i = 0
        return self
        
    def __next__ (self) -> str:
        if self.i < self.pot:
            tmp = bin (self.i) [2:].zfill (self.k) # Para tirar o 0b do início e preencher com zeros à esquerda
            self.i += 1
            return tmp
        else:
            raise StopIteration

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:

        binariosK = iter (BinariosK (k))
        pedacos = s [0:len (s):k]
        
        for v in binariosK:
            if (not (v in pedacos)) and (not (v in s)):
                return False
            
        return True # Encontrou todos
    
