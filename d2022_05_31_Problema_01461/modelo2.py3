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
            v = self.i
            tmp = ""
            
            while v != 0:
                tmp += self.bits [int (v % 2)]
                v //= 2
                
            tmp = tmp [::-1] # Inverte
            tmp = tmp.zfill (self.k)
            
            self.i += 1
            
            return tmp
        else:
            raise StopIteration

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:

        binariosK = iter (BinariosK (k))
        
        for v in binariosK:
            try:
                s.index (v)
            except:
                return False
            
        return True # Encontrou todos
    
