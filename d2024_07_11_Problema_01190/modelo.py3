class Solution:
    def reverseParentheses(self, s: str) -> str:
        pilha = list ()
        pilha.append (list ()) # A posição 0 irá ser a resposta; inicialmente vazia
        for c in s:
            if c == '(':
                pilha.append (list ()) # Inicia com uma lista vazia
            elif c == ')':
                tmp = pilha.pop ()
                topo = pilha.pop () # Irá mesclar as duas
                topo.extend (tmp [::-1])
                pilha.append (topo)
            else: # Só pode ser uma letra
                pilha [-1].append (c)
        return "".join (pilha [0])

