class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def contar (s: str) -> list:
            m = [0] * 26
            for o in [ord (c) - ord ('a') for c in s]:
                m [o] += 1
            return m

        mapa = contar (chars)

        def buscar (p: str) -> bool:
            cont = contar (p)
            for i, qtd in enumerate (cont):
                if mapa [i] < qtd:
                    return False
            return True

        resposta = 0
        for palavra in words:
            if buscar (palavra):
                resposta += len (palavra)

        return resposta

