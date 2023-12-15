class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        destinos = set ()
        # Poderia ser em linha única, mas o laço seria executado duas vezes
        for caminho in paths:
            destinos.add (caminho [1])
        for caminho in paths:
            destinos.discard (caminho [0])
        return list (destinos)[0] # Só conterá um

