class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        perdas = defaultdict (int)
        for v, p in matches: # Só tem dois itens; 1o vitória, 2o perda
            perdas [v] += 0 # Ganhou, para constar na lista de trabalho
            perdas [p] += 1 # Perdeu, soma 1
        soVitorias = [i for i, v in perdas.items () if v == 0]
        umaPerda = [i for i, v in perdas.items () if v == 1]
        soVitorias.sort ()
        umaPerda.sort ()
        return [soVitorias, umaPerda]
    
