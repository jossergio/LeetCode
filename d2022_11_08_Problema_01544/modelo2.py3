class Solution:
    def makeGood(self, s: str) -> str:
        pilha = list ()
        for c in s:
            if pilha and abs (ord (pilha [-1]) - ord (c)) == 32:
                pilha.pop ()
            else:
                pilha.append (c)
        return "".join (pilha)
    
