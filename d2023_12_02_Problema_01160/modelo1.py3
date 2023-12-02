class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def contar (s: str) -> dict:
            m = defaultdict (int) # Descentende de dict
            for c in s:
                m [c] += 1
            return m

        mapa = contar (chars)

        def buscar (p: str) -> bool:
            m = mapa.copy () # Global
            cont = contar (p)
            for c, qtd in cont.items ():
                if m.get (c, 0) < qtd:
                    return False
            return True

        resposta = 0
        for palavra in words:
            if buscar (palavra):
                resposta += len (palavra)

        return resposta

