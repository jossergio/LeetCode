class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        t = len (s)
        lista = list (s)
        if lista [t - 1] != "1":
            lista [t - 1], lista [lista.index ("1")] = "1", "0" # Não há necessidade de ser o valor das posições, pois são esses valores
        for i in range (0, t - 1):
            if lista [i] != "0":
                continue
            permuta = False
            for j in range (i + 1, t - 1):
                if lista [j] == "1":
                    lista [i], lista [j] = "1", "0" # Igual acima
                    permuta = True
                    break
            if not permuta:
                break
        return "".join (lista)
    
