class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        derrotas = defaultdict (int)
        jogadores = set ()
        for partida in matches:
            derrotas [partida [1]] += 1 # O segundo foi o derrotado
            jogadores.add (partida [0])
            jogadores.add (partida [1])
        derrotados = set ([i for i in derrotas.keys ()])
        vencedores = jogadores - derrotados
        resposta = list () # Para facilitar a visualização
        resposta.append (sorted (vencedores))
        resposta.append (sorted ([i for i, v in derrotas.items () if v == 1]))
        return resposta

