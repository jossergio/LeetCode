class Solution:
    def makeFancyString(self, s: str) -> str:
        lista = list ()
        acumulado = list ()
        anterior = s [0]
        for c in s:
            if c == anterior:
                lista.append (c)
            else:
                lista = lista [:2] # Mesmo que o tamanho seja 2
                acumulado.append (lista)
                anterior = c
                lista = [c]
        lista = lista [:2] # O último fica, depois do laço
        acumulado.append (lista)
        return "".join ("".join (a) for a in acumulado)
    
