class Solution:
    def transformar (self, s: str) -> str:
        anterior = s [0]
        contar = 1 # Já inicia o primeiro
        retorno = ""
        for c in s [1:]:
            if anterior == c:
                contar += 1
            else:
                retorno += (str (contar) + anterior)
                anterior = c
                contar = 1 # Reinicia
        return retorno + str (contar) + anterior

    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        # else
        return self.transformar (self.countAndSay (n - 1))

