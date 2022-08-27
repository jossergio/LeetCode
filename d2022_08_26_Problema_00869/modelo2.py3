class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        
        valores = list ()
        i = 1
        while (i <= 1000000000):
            valores.append (Counter (str (i)))
            i *= 2
        
        return Counter (str (n)) in valores
    
