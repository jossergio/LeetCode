class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        palavras = s.split (" ")
        tamanhoPalavras = len (palavras)
        
        if len (pattern) != tamanhoPalavras:
            return False
        
        indicePalavras = 0 # Inicial; serve para ambos
        tabela = dict ()
        
        while indicePalavras < tamanhoPalavras:
             # Dicionários Python e setdefault permitem as linhas abaixo
            valor = tabela.setdefault (pattern [indicePalavras], palavras [indicePalavras])
            if valor != palavras [indicePalavras]:
                return False
            indicePalavras += 1

        tamanhoValores = len (set (tabela.values ()))
        tamanhoIndices = len (set (pattern))
        
        if tamanhoIndices != tamanhoValores:
            return False

        return True

