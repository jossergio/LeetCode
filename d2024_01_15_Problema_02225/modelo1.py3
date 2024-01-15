class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        derrotas = defaultdict (int)
        vitoriosos = set ()
        for partida in matches:
            derrotas [partida [1]] += 1 # O segundo foi o derrotado
            vitoriosos.add (partida [0]) # O primeiro foi o vitorioso
        derrotados = set ([i for i in derrotas.keys ()])
        vencedores = vitoriosos - derrotados
        resposta = list () # Para facilitar a visualização
        resposta.append (sorted (vencedores))
        resposta.append (sorted ([i for i, v in derrotas.items () if v == 1]))
        return resposta

