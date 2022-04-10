class Solution:
    def calPoints(self, ops: List[str]) -> int:
        
        acumulador = list ()
        
        for item in ops:
            tmp = len (acumulador)
            if item == "+":
                acumulador.append (acumulador [tmp - 1] + acumulador [tmp - 2])
            elif item == "D":
                acumulador.append (acumulador [tmp - 1] * 2)
            elif item == "C":
                acumulador.pop ()
            else:
                acumulador.append (int (item))
        
        return sum (acumulador)
    
