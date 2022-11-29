class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        perdas = defaultdict (int)
        for item in matches:
            perdas [item [0]] += 0 # Ganhou, para constar na lista de trabalho
            perdas [item [1]] += 1 # Perdeu, soma 1
        return [sorted ([i for i, v in perdas.items () if v == 0]), sorted ([i for i, v in perdas.items () if v == 1])]
    
