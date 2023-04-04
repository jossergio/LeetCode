class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        resposta = [0] * len (spells)
        spellsIndex = [(valor, indice) for indice, valor in enumerate (spells)]
        spellsIndex.sort () # Pelo 1o valor da tupla
        potions.sort ()
        indexPotions = len (potions) - 1
        for valor, indice in spellsIndex:
            while indexPotions >= 0 and potions [indexPotions] * valor >= success:
                indexPotions -= 1
            resposta [indice] = len (potions) - indexPotions - 1
        return resposta
    
