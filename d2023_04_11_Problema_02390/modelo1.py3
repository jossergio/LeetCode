class Solution:
    def removeStars(self, s: str) -> str:
        resposta = list ()
        for c in s:
            if c =='*':
                resposta.pop ()
            else:
                resposta.append (c)
        return "".join (resposta)
    
