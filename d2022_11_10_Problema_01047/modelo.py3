class Solution:
    def removeDuplicates(self, s: str) -> str:
        pilha = list ()
        lista = list (s)
        i = 0
        while i < len (lista):
            if len (pilha) == 0 or pilha [-1] != lista [i]:
                pilha.append (lista [i])
            else:
                pilha.pop () # Remove o mais recente; com certeza é igual
            i += 1
        return "".join (pilha)
    
