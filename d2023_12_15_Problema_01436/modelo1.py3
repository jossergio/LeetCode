class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        origens = set ()
        destinos = set ()
        # Poderia ser em linha única, mas o laço seria executado duas vezes
        for caminho in paths:
            origens.add (caminho [0])
            destinos.add (caminho [1])
        return list (destinos - origens)[0] # Só conterá um

