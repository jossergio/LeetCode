class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        
        t = len (colors)
        
        contarA = 0
        p = 0
        while p < t:
            p = colors.find ("AAA", p)
            if p == -1:
                break
            # else
            p += 1
            contarA += 1
        
        contarB = 0
        p = 0
        while p < t:
            p = colors.find ("BBB", p)
            if p == -1:
                break
            # else
            p += 1
            contarB += 1
            
        return contarA > contarB # Se igual, a vantagem é de B
    
