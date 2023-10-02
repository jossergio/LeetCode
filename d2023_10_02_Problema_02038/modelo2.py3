class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        contarA = 0
        while "AAA" in colors:
            t = len (colors)
            colors = colors.replace ("AAA", "AA")
            contarA += t - len (colors)
        
        contarB = 0
        while "BBB" in colors:
            t = len (colors)
            colors = colors.replace ("BBB", "BB")
            contarB += t - len (colors)

        return contarA > contarB # A inicia, mas a vantagem é de B
    
